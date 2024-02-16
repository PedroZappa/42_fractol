/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:11:18 by passunca          #+#    #+#             */
/*   Updated: 2024/02/12 22:11:50 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_handle_zoom(int button, int x, int y, t_display *d);

/* Handle Mouse input: int (*f)(int button, int x, int y, void *param)
 *		Handle Zoom in with mouse wheel
 *		Handle Zoom out with mouse wheel
 *
 *	*/
int	ft_handle_mouse(int button, int x, int y, t_display *d)
{
	if ((button == Button1) && ((d->set == MANDELBROT) || (d->set == JULIA)))
	{
		ft_printf("Mouse: (%d, %d)\n", d->c_julia.r, d->c_julia.i);
		d->c_julia.r = ft_map(x, d->win_size, d->frac_range);
		d->c_julia.i = ft_map(y, d->win_size, d->frac_range);
		d->name = "Julia";
		d->set = JULIA;
		ft_printf("Mouse: (%d, %d)\n", d->c_julia.r, d->c_julia.i);
	}
	else if (button == Button2)
	{
		d->name = "Mandelbrot";
		d->set = MANDELBROT;
	}
	else if ((button == Button4) || (button == Button5))
		ft_handle_zoom(button, x, y, d);
	ft_render(d);
	return (0);
}

static void	ft_handle_zoom(int button, int x, int y, t_display *d)
{
	if (button == Button4)
	{
		d->x_offset += (ft_map(x, d->win_size, d->frac_range) * fabs(d->zoom))
			* 0.05;
		d->y_offset += (ft_map(y, d->win_size, d->frac_range) * fabs(d->zoom))
			* 0.05;
		d->zoom /= SCALE_FACTOR;
	}
	else if (button == Button5)
	{
		d->x_offset -= (ft_map(x, d->win_size, d->frac_range) * fabs(d->zoom))
			* 0.05;
		d->y_offset -= (ft_map(y, d->win_size, d->frac_range) * fabs(d->zoom))
			* 0.05;
		d->zoom *= SCALE_FACTOR;
	}
	else
	{
		ft_printf("Unknown mouse: %d\n", button);
		return ;
	}
}
