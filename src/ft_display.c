/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:46:00 by passunca          #+#    #+#             */
/*   Updated: 2024/02/02 16:07:23 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	ft_init_display : Connects to the X server
 *		mlx_init() : Initializes the display connection;
 *	*/
void	ft_init_display(t_display *display)
{
	display->mlx_conn = mlx_init();
	if (!display->mlx_conn)
		ft_kill_werror(display); // malloc_error()
	display->mlx_win = mlx_new_window(display->mlx_conn, 
								WIDTH, HEIGHT, 
								"Z's Fract'ol");
	if (!display->mlx_win)
		ft_kill_werror(display);
}

void	ft_render(t_display *display)
{
	(void)display;
}
