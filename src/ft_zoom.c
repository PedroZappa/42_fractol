/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:30:08 by passunca          #+#    #+#             */
/*   Updated: 2024/02/05 21:06:05 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_interpolate(double factor, double min, double max);

/*	Handles zooming with the mouse
 *		When a mouse scroll even occurs
 *			Calculates mouse position (r, i) relative to current zoom level
 *			(This is done by normalizing the mouse position to a range)
 *			If the scroll event was a scroll up or down
 *					Zoom in or out
 *			Set the factor to use for interpolation
 *			Adjust the min and max boundaries of the display, interpolating 
 *			between the current and the target boundaries based on the factor;
 *		Render the new image;
 *	*/
int	ft_zoom(int keycode , int x, int y, t_display *display)
{
	t_complex	mouse;
	double		factor;

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
		factor = (1.0 / display->zoom);
		display->min.r = ft_interpolate(factor, mouse.r, display->min.r);
		display->min.i = ft_interpolate(factor, mouse.i, display->min.i);
		display->max.r = ft_interpolate(factor, mouse.r, display->max.r);
		display->max.i = ft_interpolate(factor, mouse.i, display->max.i);
		ft_render(display);
	}
	else
		ft_printf("Unkown mouse input = %d\n", keycode);
	return (0);
}

static double	ft_interpolate(double factor, double min, double max)
{
	return (min + ((max - min) * factor));
}

