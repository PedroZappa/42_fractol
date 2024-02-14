/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:50:26 by passunca          #+#    #+#             */
/*   Updated: 2024/02/12 22:14:18 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_handle_offset(int keysym, t_display *d);
static void	ft_switch_set(int keysym, t_display *d);
static void	ft_switch_color(int keysym, t_display *d);

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
	else if ((keysym == XK_Left) || (keysym == XK_Right)
		|| (keysym == XK_Up) || (keysym == XK_Down))
		ft_handle_offset(keysym, d);
	else if (keysym == XK_Page_Up)
		d->iter += 7;
	else if (keysym == XK_Page_Down)
		d->iter -= 7;
	else if (keysym == XK_space)
		ft_switch_set(keysym, d);
	else if ((keysym == XK_Shift_L) || (keysym == XK_Shift_R)
		|| (keysym == XK_q) || (keysym == XK_r) || (keysym == XK_g)
		|| (keysym == XK_b))
		ft_switch_color(keysym, d);
	else
	{
		ft_printf("Unknown key: %d\n", keysym);
		return (0);
	}
	ft_render(d);
	return (1);
}

static void	ft_handle_offset(int keysym, t_display *d)
{
	if (keysym == XK_Left)
		d->x_offset += ft_absd(OFFSET_X * d->zoom);
	else if (keysym == XK_Right)
		d->x_offset -= ft_absd(OFFSET_X * d->zoom);
	else if (keysym == XK_Up)
		d->y_offset += ft_absd(OFFSET_Y * d->zoom);
	else if (keysym == XK_Down)
		d->y_offset -= ft_absd(OFFSET_Y * d->zoom);
}

static void	ft_switch_set(int keysym, t_display *d)
{
	if (keysym == XK_space)
	{
		d->set = (d->set + 1) % SETS;
		if (d->set == MANDELBROT)
			d->name = "Mandelbrot";
		else if (d->set == JULIA)
			d->name = "Julia";
		else if (d->set == TRICORN)
			d->name = "Tricorn";
		else if (d->set == NEWTON)
			d->name = "Newton";
	}
}

static void	ft_switch_color(int keysym, t_display *d)
{
	if (keysym == XK_Shift_L)
		d->color_range = ft_init_range(HEX_WHITE, HEX_BLACK);
	if (keysym == XK_Shift_R)
		d->color_range = ft_init_range(ft_argb(0, 255, 055, 255),
				ft_argb(255, 0, 0, 0));
	else if (keysym == XK_r)
		d->color_range = ft_init_range(HEX_BLACK, HEX_RED);
	else if (keysym == XK_g)
		d->color_range = ft_init_range(HEX_BLACK, HEX_GREEN);
	else if (keysym == XK_b)
		d->color_range = ft_init_range(HEX_BLACK, HEX_BLUE);
	else if (keysym == XK_q)
		d->color_range = ft_init_range(HEX_BLACK, HEX_WHITE);
}
