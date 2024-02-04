/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:58:49 by passunca          #+#    #+#             */
/*   Updated: 2024/02/04 11:24:14 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	Command line arguments checker
 *	*/
int	ft_args(t_display *display, int argc, char **argv)
{
	if (ft_help_flag(argc, argv) == 1)
		return (ft_usage());
	if (ft_select_fractal(display, argv) == 0)
		return (ft_invalid_args(argv[1]));
	if (ft_set_complex(display, argc, argv) == 0)
		return (0);
	return (1);
}

int	ft_select_fractal(t_display *display, char **argv)
{
	char *name;
	name = ft_stolower(argv[1]);
	name = argv[1];
	if (!ft_strcmp(name, "mandelbrot"))
		display->name = "mandelbrot";
	else if (!ft_strcmp(name, "julia"))
		display->name = "julia";
	else
		return (0);
	return (1);
}

int	ft_set_complex(t_display *display, int argc, char **argv)
{
	(void)display;
	(void)argc;
	(void)argv;
	return (1);
}

int	ft_invalid_args(char *name)
{
	ft_perror_color("Invalid argument: ", RED);
	ft_perror(name);
	ft_perror_color("\nHere are all the available options:\n", RED);
	ft_usage();
	return (0);
}

int	ft_no_args(void)
{
	ft_perror("No arguments provided.\nHere are all the available options:\n");
	ft_usage();
	return (0);	
}
