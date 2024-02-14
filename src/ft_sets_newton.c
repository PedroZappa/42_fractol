/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sets_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:34:26 by passunca          #+#    #+#             */
/*   Updated: 2024/02/12 22:38:34 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			calculate_newton(t_display *d);
static unsigned		ft_check_roots(t_display *d);
static void			ft_init_roots(t_complex *roots);
static t_complex	ft_get_diff(t_complex z_newton, t_complex root);

void	render_newton(t_display *d, int x, int y)
{
	int			i;
	int			color;

	i = 0;
	ft_set_scale(d, &d->z_newton, x, y);
	while (i++ < d->iter)
	{
		calculate_newton(d);
		if (!ft_check_roots(d))
		{
			color = (ft_map(i, d->color_iter, d->color_range) * 5);
			return (ft_put_pixel(d->img, x, y, color));
		}
	}
	ft_put_pixel(d->img, x, y, d->color);
}

static void	calculate_newton(t_display *d)
{
	t_complex	next;
	double		denominator;

	denominator = (3 * ((d->z_newton.r * d->z_newton.r)
		+ (d->z_newton.i * d->z_newton.i)));
	next.r = (((d->z_newton.r * d->z_newton.r * d->z_newton.r * d->z_newton.r 
		* d->z_newton.r) + (2 * d->z_newton.r * d->z_newton.r * d->z_newton.r
		* d->z_newton.i * d->z_newton.i) - (d->z_newton.r * d->z_newton.r)
		+ (d->z_newton.r * d->z_newton.i * d->z_newton.i * d->z_newton.i 
		* d->z_newton.i) + (d->z_newton.i * d->z_newton.i)) / denominator);
	next.i = ((d->z_newton.i * ((d->z_newton.r * d->z_newton.r * d->z_newton.r 
		* d->z_newton.r) + (2 * d->z_newton.r * d->z_newton.r * d->z_newton.i 
		* d->z_newton.i) + (2 * d->z_newton.r) + (d->z_newton.i * d->z_newton.i
		* d->z_newton.i * d->z_newton.i)) / denominator));
	d->z_newton.r -= next.r;
	d->z_newton.i -= next.i;
}

static unsigned ft_check_roots(t_display *d)
{
	static t_complex	roots[3];
	t_complex			diff;

	ft_init_roots(roots);
	diff = ft_get_diff(d->z_newton, roots[0]);
	if ((ft_abs(diff.r) < d->newton_escape)
		&& (ft_abs(diff.i) < d->newton_escape))
		return (1);
	diff = ft_get_diff(d->z_newton, roots[1]);
	if ((ft_abs(diff.r) < d->newton_escape)
		&& (ft_abs(diff.i) < d->newton_escape))
		return (1);
	diff = ft_get_diff(d->z_newton, roots[2]);
	if ((ft_abs(diff.r) < d->newton_escape)
		&& (ft_abs(diff.i) < d->newton_escape))
		return (1);
	return (0);
}

static void	ft_init_roots(t_complex *roots)
{
	static unsigned set;

	if (!set)
	{
		roots[0] = (t_complex){1, 0};
		roots[1] = (t_complex){0.5, 0.866025403784438};
		roots[2] = (t_complex){0.5, -0.866025403784438};
		set = 1;
	}
}

static t_complex	ft_get_diff(t_complex z_newton, t_complex root)
{
	t_complex	diff;

	diff.r = (z_newton.r - root.r);
	diff.i = (z_newton.i - root.i);
	return (diff);
}
