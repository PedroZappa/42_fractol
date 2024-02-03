/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:50:26 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 21:37:42 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	Setup hook for pressed keys;
*	Setup hook for mouse clicks;
*	Setup hook to listen clicking X on the window
 *	*/
void	ft_events_init(t_display *display)
{
	mlx_hook(display->mlx_win, KeyPress, KeyPressMask, ft_handle_keys, display);
	// mlx_hook(display->mlx_win, ButtonPress, ButtonPressMask, handle_mouse, 
	// 	  display);
	mlx_hook(display->mlx_win, DestroyNotify, StructureNotifyMask, 
		  ft_kill_handle, display);
}

/*	Handle key input: int (*f)(int keycode, void *param)
 *		If `XK_Escape` keysym is received, 
 *		Handle Left and right offset
 *		Handle Up and down offset
 *		Handle change of iterations;
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
		display->x_offset += .3;
	else if (keysym == XK_Right)
		display->x_offset -= .3;
	else if (keysym == XK_Up)
		display->y_offset -= .3;
	else if (keysym == XK_Down)
		display->y_offset += .3;
	else if (keysym == XK_KP_Add)
		display->iter += 64;
	else if (keysym == XK_KP_Subtract)
		display->iter -= 64;

	ft_render(display);
	return (0);
}

