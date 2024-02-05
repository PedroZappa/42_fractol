/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:50:26 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 22:06:42 by passunca         ###   ########.fr       */
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
	mlx_hook(display->mlx_win, ButtonPress, ButtonPressMask, ft_handle_mouse, 
		  display);
	mlx_hook(display->mlx_win, DestroyNotify, StructureNotifyMask, 
		  ft_kill_handle, display);
}

/*	Handle key input: int (*f)(int keycode, void *param)
 *		If `XK_Escape` keysym is received, 
 *		Handle Left and right offset, scale it with zoom
 *		Handle Up and down offset, scale it with zoom
 *		Handle change of iterations (PageUp PageDown);
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
	else if (keysym == XK_Left || keysym == XK_KP_Left)
		display->x_offset += (0.3 * display->zoom);
	else if (keysym == XK_Right || keysym == XK_KP_Right)
		display->x_offset -= (0.3 * display->zoom);
	else if (keysym == XK_Up || keysym == XK_KP_Up)
		display->y_offset -= .3;
	else if (keysym == XK_Down || keysym == XK_KP_Down)
		display->y_offset += .3;
	else if (keysym == 65365)
		display->iter += 21;
	else if (keysym == 65366)
		display->iter -= 21;

	ft_render(display);
	return (0);
}

/* Handle Mouse input: int (*f)(int button, int x, int y, void *param) 
 *		Handle Zoom in with mouse wheel
 *		Handle Zoom out with mouse wheel
 *
 *	*/
int	ft_handle_mouse(int button, int x, int y, t_display *display)
{
	(void)x;
	(void)y;
	if (button == Button4)
		display->zoom *= 0.95;
	else if (button == Button5)
		display->zoom *= 1.05;
	printf("%d\n", button);
	ft_render(display);
	return (0);
}
