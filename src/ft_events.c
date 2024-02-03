/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:50:26 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 21:00:59 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	Setup hook for pressed keys;
*	Setup hook for mouse clicks;
*	Setup hook to listen for destroy event
 *	*/
void	ft_events_init(t_display *display)
{
	mlx_hook(display->mlx_win, KeyPress, KeyPressMask, ft_handle_keys, display);
	// mlx_hook(display->mlx_win, ButtonPress, ButtonPressMask, handle_mouse, 
	// 	  display);
	// mlx_hook(display->mlx_win, DestroyNotify, StructureNotifyMask, kill_handle,
	// 	  display);
}

/*	Handle key input
 *		If `XK_Escape` keysym is received, 
 *		destroy the window and exit.
 *	*/
int	ft_handle_keys(int keysym, t_display *display)
{
	ft_printf("%d\n", keysym);
	if (keysym == XK_Escape)
	{
		ft_printf("Exiting Fract'ol...bubye!\n");
		ft_kill_handle(display);
	}
	else if (keysym == XK_Left)
		;
	else if (keysym == XK_Right)
		;
	else if (keysym == XK_Up)
		;
	else if (keysym == XK_Down)
		;
	else if (keysym == XK_plus)
		display->iter += 64;
	else if (keysym == XK_minus)
		display->iter -= 64;
	return (0);
}

