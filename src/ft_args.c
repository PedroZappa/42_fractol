/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:58:49 by passunca          #+#    #+#             */
/*   Updated: 2024/02/04 12:01:48 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_set_args(t_display *display, int argc, char **argv);
static int	ft_invalid_args(char *name);

/*	Command line arguments checker
 *	*/
int	ft_args(t_display *display, int argc, char **argv)
{
	if (!ft_select_fractal(display, argc, argv))
		return (ft_invalid_args(argv[1]));
	if (!ft_set_args(display, argc, argv))
		return (0);
	return (1);
}

int	ft_select_fractal(t_display *display, int argc, char **argv)
{
	char *name;
	name = ft_stolower(argv[1]);
	if (!ft_strcmp(name, "mandelbrot") && (argc == 3))
	{
		display->set = MANDELBROT;
		display->name = "Mandelbrot";
		display->iter = ft_atoi(argv[2]);
	}
	// else if (!ft_strcmp(name, "julia") && (argc == 5))
	else if (!ft_strcmp(name, "julia"))
	{
		display->set = JULIA;
		display->name = "Julia";
		display->iter = ft_atoi(argv[2]);
	}
	else
		return (0);
	return (1);
}

static int	ft_set_args(t_display *display, int argc, char **argv)
{
	if (((argc > 2) && (argc < 5)) && !ft_is_argint(argv[2]))
		return (ft_kill_werror("Invalid arguments\n"));
	else if ((argc == 3) || (argc == 5))
	{
		display->iter = ft_atoi(argv[2]);
		if (display->iter <= 0)
			display->iter = INIT_ITER;
	}
	if ((argc > 5) && ((!ft_is_argdbl(argv[3])) || (!ft_is_argdbl(argv[4]))))
		return (ft_kill_werror("Invalid argument type\n"));
	else if (argc == 5)
	{
		display->c_julia.r = ft_atod(argv[3]);
		display->c_julia.i = ft_atod(argv[4]);
	}
	return (1);
}

static int	ft_invalid_args(char *name)
{
	ft_sep_color('#', '=', 40, GRN);
	ft_perror_color("Invalid argument: ", RED);
	ft_printf("%s\n", name);
	ft_usage();
	return (0);
}

int	ft_no_args(void)
{
	ft_perror_color("No arguments provided.\n", RED);
	ft_usage();
	exit(EXIT_FAILURE);	
}
