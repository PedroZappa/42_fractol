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

void	ft_render_ui(t_display *d)
{
	mlx_string_put(d->mlx_conn, d->mlx_win, 10, 20, HEX_WHITE, d->name);
	mlx_string_put(d->mlx_conn, d->mlx_win, 10, 40, HEX_WHITE,
		ft_strjoin("iter: ", ft_itoa(d->iter)));
}
