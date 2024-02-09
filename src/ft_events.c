/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:50:26 by passunca          #+#    #+#             */
/*   Updated: 2024/02/05 20:38:23 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	Setup hook for pressed keys;
*	Setup hook for mouse clicks;
*	Setup hook to listen clicking X on the window
 *	*/
void	ft_events_init(t_display *d)
{
	mlx_hook(d->mlx_win, KeyPress, KeyPressMask, ft_handle_keys, d);
	mlx_hook(d->mlx_win, DestroyNotify, StructureNotifyMask, 
		  ft_kill_handle, d);
	mlx_hook(d->mlx_win, ButtonPress, ButtonPressMask, ft_handle_mouse, 
		  d);
}

/*	Handle key input: int (*f)(int keycode, void *param)
 *		If `XK_Escape` keysym is received, destroy window and exit.
 *		Handle Left and right offset, scale it with zoom
 *		Handle Up and down offset, scale it with zoom
 *		Handle change of iterations (PageUp PageDown);
 *	*/
int	ft_handle_keys(int keysym, t_display *d)
{
	if (keysym == XK_Escape)
		ft_kill_handle(d);
	else if (keysym == XK_Left || keysym == XK_KP_Left)
		d->x_offset -= (0.3 * d->zoom);
	else if (keysym == XK_Right || keysym == XK_KP_Right)
		d->x_offset += (0.3 * d->zoom);
	else if (keysym == XK_Up || keysym == XK_KP_Up)
		d->y_offset -= (0.3 * d->zoom);
	else if (keysym == XK_Down || keysym == XK_KP_Down)
		d->y_offset += (0.3 * d->zoom);
	else if (keysym == XK_Page_Up)
		d->iter += 21;
	else if (keysym == XK_Page_Down)
		d->iter -= 21;
	else
		ft_printf("Unknown key: %d\n", keysym);
	ft_render(d);
	return (0);
}

/* Handle Mouse input: int (*f)(int button, int x, int y, void *param) 
 *		Handle Zoom in with mouse wheel
 *		Handle Zoom out with mouse wheel
 *
 *	*/
int	ft_handle_mouse(int button, int x, int y, t_display *d)
{
	(void)x;
	(void)y;
	(void)button;
	if (button == Button4)
		d->zoom *= 0.95;
	else if (button == Button5)
		d->zoom *= 1.05;
	else
		ft_printf("Unknown mouse: %d\n", button);
	ft_render(d);
	return (0);
}
