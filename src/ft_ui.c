/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:05:07 by passunca          #+#    #+#             */
/*   Updated: 2024/02/12 16:08:24 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
