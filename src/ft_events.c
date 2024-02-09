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
		d->x_offset -= (OFFSET_X * d->zoom);
	else if (keysym == XK_Right || keysym == XK_KP_Right)
		d->x_offset += (OFFSET_X * d->zoom);
	else if (keysym == XK_Up || keysym == XK_KP_Up)
		d->y_offset -= (OFFSET_Y * d->zoom);
	else if (keysym == XK_Down || keysym == XK_KP_Down)
		d->y_offset += (OFFSET_Y * d->zoom);
	else if (keysym == XK_Page_Up)
		d->iter += 21;
	else if (keysym == XK_Page_Down)
		d->iter -= 21;
	else
	{
		ft_printf("Unknown key: %d\n", keysym);
		return (0);
	}
	ft_render(d);
	return (1);
}

/* Handle Mouse input: int (*f)(int button, int x, int y, void *param) 
 *		Handle Zoom in with mouse wheel
 *		Handle Zoom out with mouse wheel
 *
 *	*/
int	ft_handle_mouse(int button, int x, int y, t_display *d)
{
	mlx_mouse_get_pos(d->mlx_conn, d->mlx_win, &x, &y);
	if (button == Button4)
	{
		 d->x_offset += -(ft_map(x, d->win_size, d->frac_range) * 0.01);
		 d->y_offset += -(ft_map(y, d->win_size, d->frac_range) * 0.01);
		d->zoom /= SCALE_FACTOR;
	}
	else if (button == Button5)
	{
		 d->x_offset -= -(ft_map(x, d->win_size, d->frac_range) * 0.01);
		 d->y_offset -= -(ft_map(y, d->win_size, d->frac_range) * 0.01);
		 d->zoom *= SCALE_FACTOR;
	}
	else
	{
		ft_printf("Unknown mouse: %d\n", button);
		return (0);
	}
	ft_printf("Cursor at X: %d Y: %d\n", x, y);
	ft_render(d);
	return (0);
}
