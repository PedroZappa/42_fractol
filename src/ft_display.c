/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:46:00 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 22:52:15 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	ft_render : Renders the fractal
 *		Get all the pixels
 *		Pushes image into the window
 *	*/
void	ft_render(t_display *display)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_get_pixel(display, x, y);
		ft_printf("\rRendering: [%d%%]", ((y * 100) / display->height) + 1);
	}
	ft_pout_color("\tComplete!\n", MAG);
	mlx_put_image_to_window(display->mlx_conn, display->mlx_win,
		display->img.img, 0, 0);
	return ;
}

/*	ft_put_pixel : Puts a pixel to the display
 *		Initialize z.r and z.i to 0.0
 *		Scale pixel coordinates to fit the mandelbrot range:
 *			Scale x from the range (0 to WIDTH) to (-2.0 to 2.0) [left to right]
 *			Scale y from the range (0 to WIDTH) to (2.0 to -2.0) [top to bottom]
 *		Plug pixel coordinates into the Mandelbrot equation
 *			Compute z = z^2 + c
 *			Loop for i iterations
 *				Set z to the result of (z^2 + c)
 *				Check if z is in the Mandelbrot set (Check Pythagorean theorem)
 *					Scale the range (0 to HEX_WHITE) to (0 to i)
 *	*/
void	ft_get_pixel(t_display *display, int x, int y)
{
	int			color;
	int			i;

	i = -1;
	display->z.r = 0;
	display->z.i = 0;
	display->c.r = (ft_map(x, display->win_size, display->frac_range)
		* display->zoom) + display->x_offset;
	display->frac_range.min = 2.0;
	display->frac_range.max = -2.0;
	display->c.i = (ft_map(y, display->win_size, display->frac_range)
		* display->zoom) + display->y_offset;
	while (++i < display->iter)
	{
		display->z = ft_c_sum(ft_c_square(display->z), display->c);
		// display->z_old.r = display->c.r;
		// display->z_old.i = display->c.i;
		// display->c.r = ((display->z_old.r * display->z_old.r)
		// 	- (display->z_old.i * display->z_old.i)) + display->c.r;
		// display->c.i = (2.0 * display->z_old.r * display->z_old.i)
		// 	+ display->c.i;
		if (((display->z.r * display->z.r) + (display->z.i * display->z.i))
				> display->escape)
		{
			color = ft_map(i, display->color_iter, display->color_range);
			ft_put_pixel(display->img, x, y, color);
			return ;
		}
	}
	ft_put_pixel(display->img, x, y, HEX_PURPLE);
}

/*	ft_put_pixel : Puts a pixel to the display
 *										 img->bpp
 *	offset = (y * img->line_len) + ( x * -------- )
 *										    8
 *		offset : stores the byte offset within the image data array where the
 *		information should be placed;, accounting for the possibility of
 *		padding bytes at the end of each row;
 *		1. Multiply the y-coordinate by the line length to find the starting
 *		position of the row in the buffer. This accounts for the width of the
 *		image and any padding.
 *		2. Multiply the x-coordinate by the size of each pixel in bytes (bits
 *		per_pixel / 8) to find the position of the pixel within the row.
 *		3. Add these two values together to get the overall byte offset within
 *		the buffer.
 *
 *		Note: This formula assumes that the image data is stored in a linear
 *		block of memory, row by row, without any compression or interlacing.
 *	*/
void	ft_put_pixel(t_img img, int x, int y, int color)
{
	int		offset;

	offset = (y * img.line_len) + (x * (img.bpp / 8));
	*(unsigned *)(img.pix + offset) = color;
}
