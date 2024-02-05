/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:50:18 by passunca          #+#    #+#             */
/*   Updated: 2024/02/04 10:53:10 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_usage(void)
{
	ft_pout_color("Fract'ol Usage:\n", YEL);
	ft_printf("\t./fractol <set> <iterations> <c.r> <c.i>\n");
	ft_sep_color('#', '=', 50, GRN);
	ft_pout_color("Controls:\n", YEL);
	ft_printf(":Move around with:\n");
	ft_printf("\t> Arrow keys\n\t> Numpad keys\n");
	ft_printf(":Zoom in and out with:\n");
	ft_printf("\t> Mouse wheel\n");
	ft_printf(":Change color scheme with:\n");
	ft_printf("\t> Spacebar\n");
	ft_printf(":Switch between Sets with:\n");
	ft_printf("\t> 1, 2, 3\n");
	ft_printf(":To Exit press:\n");
	ft_printf("\t> ESC\n");
	ft_sep_color('#', '=', 30, GRN);
	ft_pout_color("Available Sets:\n", YEL);
	ft_printf("\t> Mandelbrot\n\t> Julia\n\t> Newton\n");
	ft_sep_color('#', '=', 30, GRN);

	return (0);
}

/*	Check if help flag is present in the command line arguments.
 *	*/
int ft_help_flag(int argc, char **argv)
{
	int i;

	i = -1;
	while (++i < argc)
		if (ft_strcmp(argv[i], "-h") == 0)
			return (1);
	return (0);
}
