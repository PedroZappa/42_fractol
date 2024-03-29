/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:25:24 by passunca          #+#    #+#             */
/*   Updated: 2024/02/12 22:16:34 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	Mandelbrot Formula : z = z^2 + c
 *		Where z is the complex number initialized to 0
 *	*/
void	render_mandelbrot(t_display *d, int x, int y)
{
	double		zr_tmp;
	int			color;
	int			i;

	i = 0;
	d->z.r = 0;
	d->z.i = 0;
	while (++i <= d->iter)
	{
		zr_tmp = (d->z.r * d->z.r) - (d->z.i * d->z.i) + d->c.r;
		d->z.i = (2 * d->z.r * d->z.i) + d->c.i;
		d->z.r = zr_tmp;
		if (((d->z.r * d->z.r) + (d->z.i * d->z.i)) > d->escape)
		{
			color = (ft_map(i, d->color_iter, d->color_range) * 5);
			ft_put_pixel(d->img, x, y, color);
			return ;
		}
	}
	ft_put_pixel(d->img, x, y, d->color);
}

/*	Julia Formula : z = z^2 + c_julia
*		Where c_julia is a user input complex number
*	*/
void	render_julia(t_display *d, int x, int y)
{
	t_complex	z_tmp;
	int			color;
	int			i;

	i = 0;
	while (++i <= d->iter)
	{
		z_tmp.r = d->z.r;
		z_tmp.i = d->z.i;
		d->z.r = ((z_tmp.r * z_tmp.r) - (z_tmp.i * z_tmp.i) + d->c_julia.r);
		d->z.i = ((2 * z_tmp.r * z_tmp.i) + d->c_julia.i);
		if (((d->z.r * d->z.r) + (d->z.i * d->z.i)) > d->escape)
		{
			color = (ft_map(i, d->color_iter, d->color_range) * 5);
			ft_put_pixel(d->img, x, y, color);
			return ;
		}
	}
	ft_put_pixel(d->img, x, y, d->color);
}

/*	Tricorn Formula : z = z^-2 + c
 *		Where z is the complex number initialized to 0
 *	*/
void	render_tricorn(t_display *d, int x, int y)
{
	double		zr_tmp;
	int			color;
	int			i;

	i = 0;
	d->z.r = 0;
	d->z.i = 0;
	while (++i <= d->iter)
	{
		zr_tmp = (d->z.r * d->z.r) - (d->z.i * d->z.i) + d->c.r;
		d->z.i = (-2 * d->z.r * d->z.i) + d->c.i;
		d->z.r = zr_tmp;
		if (((d->z.r * d->z.r) + (d->z.i * d->z.i)) > d->escape)
		{
			color = (ft_map(i, d->color_iter, d->color_range) * 5);
			ft_put_pixel(d->img, x, y, color);
			return ;
		}
	}
	ft_put_pixel(d->img, x, y, d->color);
}

/*	Burning Ship Formula : z = (|z.r| + |z.i|)² + c
*		Where z is the complex number initialized to 0
*	*/
void	render_burning(t_display *d, int x, int y)
{
	double		zr_tmp;
	int			color;
	int			i;

	i = 0;
	d->z.r = 0;
	d->z.i = 0;
	while (++i <= d->iter)
	{
		zr_tmp = (d->z.r * d->z.r) - (d->z.i * d->z.i) + d->c.r;
		d->z.i = (fabs(2.0 * d->z.r * d->z.i)) + d->c.i;
		d->z.r = fabs(zr_tmp);
		if (((d->z.r * d->z.r) + (d->z.i * d->z.i)) > d->escape)
		{
			color = (ft_map(i, d->color_iter, d->color_range) * 5);
			ft_put_pixel(d->img, x, y, color);
			return ;
		}
	}
	ft_put_pixel(d->img, x, y, d->color);
}
