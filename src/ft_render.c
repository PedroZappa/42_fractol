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

void	ft_render_ui(t_display *d);

/*	ft_render : Renders the fractal
 *		Get all the pixels
 *		Pushes image into the window
 *	*/
void	ft_render(t_display *d)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_select_set(d, x, y);
		ft_printf("\rRendering: [%d%%]", ((y * 100) / d->height) + 1);
	}
	ft_pout_color("\tComplete!\n", MAG);
	mlx_put_image_to_window(d->mlx_conn, d->mlx_win, d->img.img, 0, 0);
	ft_render_ui(d);
	return ;
}

void	ft_select_set(t_display *d, int x, int y)
{
	if (d->set == MANDELBROT)
		render_mandelbrot(d, x, y);
	else if (d->set == JULIA)
		render_julia(d, x, y);
	else if (d->set == NEWTON)
		render_newton(d, x, y);
	else
		ft_kill_handle(d);
	return ;
}

void	ft_render_ui(t_display *d)
{
	mlx_string_put(d->mlx_conn, d->mlx_win, 15, 20, HEX_WHITE, d->name);
	if (!ft_strcmp(d->name, "Mandelbrot"))
	{
		mlx_string_put(d->mlx_conn, d->mlx_win, 15, 40, HEX_WHITE, 
				 ft_strjoin("Zoom : ", ft_dtoa(d->zoom)));
		mlx_string_put(d->mlx_conn, d->mlx_win, 15, 60, HEX_WHITE, ft_dtoa(d->c.r));
		mlx_string_put(d->mlx_conn, d->mlx_win, 15, 80, HEX_WHITE, ft_dtoa(d->c.i));
	}
	else if (!ft_strcmp(d->name, "Julia"))
	{
		mlx_string_put(d->mlx_conn, d->mlx_win, 15, 40, HEX_WHITE, ft_dtoa(d->zoom));
		mlx_string_put(d->mlx_conn, d->mlx_win, 15, 60, HEX_WHITE, ft_dtoa(d->c_julia.r));
		mlx_string_put(d->mlx_conn, d->mlx_win, 15, 80, HEX_WHITE, ft_dtoa(d->c_julia.i));
	}
}

/*	ft_put_pixel : Puts a pixel to the d
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
