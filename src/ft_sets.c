/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:25:24 by passunca          #+#    #+#             */
/*   Updated: 2024/02/02 18:12:02 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_select_set(t_display *d, int x, int y)
{
	if (d->set == MANDELBROT)
		render_mandelbrot(d, x, y);
	else if (d->set == JULIA)
		render_julia(d);
	else if (d->set == NEWTON)
		render_newton(d);
	return ;
}

void	render_mandelbrot(t_display *d, int x, int y)
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
	return ;
}

void	render_julia(t_display *d)
{
	(void)d;
	return ;
}

void	render_newton(t_display *d)
{
	(void)d;
	return ;
}
