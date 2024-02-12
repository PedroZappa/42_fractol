/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:50:18 by passunca          #+#    #+#             */
/*   Updated: 2024/02/12 17:05:27 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_usage(void)
{
	ft_sep_color('#', '=', 50, GRN);
	ft_pout_color("Fract'ol Usage:\n", YEL);
	ft_printf("\t%s./fractol <set> <iter> <c.r> <c.i>%s\n", CYN, NC);
	ft_sep_color('#', '=', 50, GRN);
	ft_pout_color("Available Sets:\n", YEL);
	ft_printf("> Mandelbrot\n\t%s./fractol <set>%s\n", CYN, NC);
	ft_printf("> Julia\n\t%s./fractol <set> <iter> <c.r> <c.i>%s\n", CYN, NC);
	ft_printf("> Newton\n\t...\n");
	ft_sep_color('#', '=', 50, GRN);
	ft_pout_color("Controls:\n", YEL);
	ft_printf(":Move around with:\n\t> Arrow keys\n\t> Numpad keys\n");
	ft_printf(":Zoom in and out with:\n\t> Mouse wheel\n");
	ft_printf(":Change n iterations with:\n\t> PageUp & PageDown\n");
	ft_printf(":Change color scheme with:\n\t> L-Shift & R-Shift\n");
	ft_printf(":Switch between Sets with:\n\t> Spacebar\n");
	ft_printf(":To Exit press:\n\t> ESC\n\t> Window's X button\n");
	ft_sep_color('#', '=', 50, GRN);
	return (0);
}
