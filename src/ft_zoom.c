/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:30:08 by passunca          #+#    #+#             */
/*   Updated: 2024/02/05 20:05:01 by passunca         ###   ########.fr       */
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
int	ft_zoom(t_display *display, int x, int y, int keycode)
{
	t_complex	mouse;
	double		zoom;
	double		inter;

	if (keycode  == Button4 || keycode == Button5)
	{
		/**/
		if (keycode == Button4)
			zoom = 1.1;
		else
			zoom = 0.9;
		inter = (1.0 / zoom);
		display->
	}
	else
		ft_printf("Unkown mouse input = %d\n", keycode);
	return (0);
}

static double	ft_interpolate(double inter, double min, double max)
{
	return (min + ((max - min) * inter));
}

