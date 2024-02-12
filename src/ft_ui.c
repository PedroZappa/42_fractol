/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:05:07 by passunca          #+#    #+#             */
/*   Updated: 2024/02/12 17:34:55 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mandelbrot_ui(t_display *d);
static void	ft_julia_ui(t_display *d);

void	ft_render_ui(t_display *d)
{
	mlx_string_put(d->mlx_conn, d->mlx_win, 15, 20, HEX_WHITE, d->name);
	if (!ft_strcmp(d->name, "Mandelbrot"))
		ft_mandelbrot_ui(d);
	else if (!ft_strcmp(d->name, "Julia"))
		ft_julia_ui(d);
}

static void	ft_mandelbrot_ui(t_display *d)
{
	mlx_string_put(d->mlx_conn, d->mlx_win, 15, 40, HEX_WHITE,
		ft_strjoin("Zoom : ", ft_dtoa(d->zoom)));
	mlx_string_put(d->mlx_conn, d->mlx_win, 15, 60, HEX_WHITE,
		ft_strjoin("z.r = ", ft_dtoa(d->z.r)));
	mlx_string_put(d->mlx_conn, d->mlx_win, 15, 80, HEX_WHITE,
		ft_strjoin("z.i = ", ft_dtoa(d->z.i)));
	mlx_string_put(d->mlx_conn, d->mlx_win, 15, 100, HEX_WHITE,
		ft_strjoin("c.r = ", ft_dtoa(d->c.r)));
	mlx_string_put(d->mlx_conn, d->mlx_win, 15, 120, HEX_WHITE,
		ft_strjoin("c.i = ", ft_dtoa(d->c.i)));
}

static void	ft_julia_ui(t_display *d)
{
	mlx_string_put(d->mlx_conn, d->mlx_win, 15, 40, HEX_WHITE,
		ft_strjoin("Zoom = ", ft_dtoa(d->zoom)));
	mlx_string_put(d->mlx_conn, d->mlx_win, 15, 60, HEX_WHITE,
		ft_strjoin("z.r = ", ft_dtoa(d->z.r)));
	mlx_string_put(d->mlx_conn, d->mlx_win, 15, 80, HEX_WHITE,
		ft_strjoin("z.i = ", ft_dtoa(d->z.i)));
	mlx_string_put(d->mlx_conn, d->mlx_win, 15, 100, HEX_WHITE,
		ft_strjoin("c.r = ", ft_dtoa(d->c_julia.r)));
	mlx_string_put(d->mlx_conn, d->mlx_win, 15, 120, HEX_WHITE,
		ft_strjoin("c.i = ", ft_dtoa(d->c_julia.i)));
}
