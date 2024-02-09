/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:25:24 by passunca          #+#    #+#             */
/*   Updated: 2024/02/02 18:12:02 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_select_set(t_display *display)
{
	if (display->set == MANDELBROT)
		render_mandelbrot(display);
	else if (display->set == JULIA)
		render_julia(display);
	else if (display->set == NEWTON)
		render_newton(display);
	return ;
}

void	render_mandelbrot(t_display *display)
{
	(void)display;
	return ;
}

void	render_julia(t_display *display)
{
	(void)display;
	return ;
}

void	render_newton(t_display *display)
{
	(void)display;
	return ;
}
