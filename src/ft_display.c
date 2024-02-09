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
void	ft_render(t_display *d)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_get_pixel(d, x, y);
		ft_printf("\rRendering: [%d%%]", ((y * 100) / d->height) + 1);
	}
	ft_pout_color("\tComplete!\n", MAG);
	mlx_put_image_to_window(d->mlx_conn, d->mlx_win, d->img.img, 0, 0);
	return ;
}

/*	ft_put_pixel : Puts a pixel to the d
 *	*/
void	ft_get_pixel(t_display *d, int x, int y)
{
	double		r_tmp;
	int			color;
	int			i;

	i = 0;
	d->z.r = 0;
	d->z.i = 0;
	d->c.r = (ft_map(x, d->win_size, d->frac_range) * d->zoom) + d->x_offset;
	d->frac_range.min = 2.0;
	d->frac_range.max = -2.0;
	d->c.i = (ft_map(y, d->win_size, d->frac_range) * d->zoom) + d->y_offset;
	while (++i < d->iter)
	{
		r_tmp = (d->z.r * d->z.r) - (d->z.i * d->z.i) + d->c.r;
		d->z.i = (2 * d->z.r * d->z.i) + d->c.i;
		d->z.r = r_tmp;
		if (((d->z.r * d->z.r) + (d->z.i * d->z.i)) > d->escape)
		{
			color = ft_map(i, d->color_iter, d->color_range);
			ft_put_pixel(d->img, x, y, color);
			return ;
		}
	}
	// ft_select_set(d, x, y);
	ft_put_pixel(d->img, x, y, HEX_GREEN);
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
