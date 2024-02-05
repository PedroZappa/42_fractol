/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:30:08 by passunca          #+#    #+#             */
/*   Updated: 2024/02/05 20:30:38 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_interpolate(double inter, double min, double max);

/*	Handles zooming with the mouse
 *		When a mouse scroll even occurs
 *			Calculates mouse position (r, i) relative to current zoom level
 *			(This is done by normalizing the mouse position to a range)
 *
 *	*/
int	ft_zoom(int keycode , int x, int y, t_display *display)
{
	t_complex	mouse;
	double		inter;

	if (keycode == Button4 || keycode == Button5)
	{
		mouse.r = (double)x / (display->width / 
			(display->max.r - display->min.r));
		mouse.i = (double)y / (display->height /
			(display->max.i - display->min.i));
		if (keycode == Button4)
			display->zoom *= 0.95;
		else
			display->zoom *= 1.05;
		inter = (1.0 / display->zoom);
		display->min.r = ft_interpolate(mouse.r, display->min.r, inter);
		display->min.i = ft_interpolate(mouse.i, display->min.i, inter);
		display->max.r = ft_interpolate(mouse.r, display->max.r, inter);
		display->max.i = ft_interpolate(mouse.i, display->max.i, inter);
		ft_render(display);
	}
	else
		ft_printf("Unkown mouse input = %d\n", keycode);
	return (0);
}

static double	ft_interpolate(double inter, double min, double max)
{
	return (min + ((max - min) * inter));
}

