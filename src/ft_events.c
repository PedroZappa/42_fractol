/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:50:26 by passunca          #+#    #+#             */
/*   Updated: 2024/02/01 21:52:13 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	Handle input
 *
 *		If `XK_Escape` keysym is received, 
 *		destroy the window and exit.
 *	*/
int	handle_input(int keysym, t_env *display)
{
	if (keysym == XK_Escape)
	{
		ft_printf("Fractol Exiting...\n");
		mlx_destroy_window(display->mlx_conn, display->mlx_win);
		mlx_destroy_display(display->mlx_conn);
		free(display->mlx_conn);
		exit(0);
	}
	ft_printf("Key %d pressed\n", keysym);
	return (0);
}
