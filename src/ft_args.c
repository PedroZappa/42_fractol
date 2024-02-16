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

static int	ft_set_args(t_display *d, int argc, char **argv);
static int	ft_invalid_args(char *name);
static void	ft_set_fractal(t_display *d, int set, char *name, int iter);

/*	Command line arguments checker
 *	*/
int	ft_args(t_display *d, int argc, char **argv)
{
	if (!ft_select_fractal(d, argc, argv))
		return (ft_invalid_args(argv[1]));
	if (!ft_set_args(d, argc, argv))
		return (0);
	return (1);
}

int	ft_select_fractal(t_display *d, int argc, char **argv)
{
	char	*name;

	name = ft_stolower(argv[1]);
	if (!ft_strcmp(name, "mandelbrot") && (argc == 3))
		ft_set_fractal(d, MANDELBROT, "Mandelbrot", ft_atoi(argv[2]));
	else if (!ft_strcmp(name, "julia") && ((argc == 3) || (argc == 5)))
		ft_set_fractal(d, JULIA, "Julia", ft_atoi(argv[2]));
	else if (!ft_strcmp(name, "tricorn") && (argc == 3))
		ft_set_fractal(d, TRICORN, "Tricorn", ft_atoi(argv[2]));
	else if (!ft_strcmp(name, "burning") && (argc == 3))
		ft_set_fractal(d, BURNING, "Burning Ship", ft_atoi(argv[2]));
	else if (!ft_strcmp(name, "newton") && (argc == 3))
		ft_set_fractal(d, NEWTON, "Newton", ft_atoi(argv[2]));
	else
		return (0);
	return (1);
}

static void	ft_set_fractal(t_display *d, int set, char *name, int iter)
{
	d->set = set;
	d->name = name;
	d->iter = iter;
}

static int	ft_set_args(t_display *d, int argc, char **argv)
{
	if (((argc > 2) && (argc < 5)) && !ft_is_argint(argv[2]))
		return (ft_kill_werror("Invalid arguments\n"));
	else if ((argc == 3) || (argc == 5))
	{
		d->iter = ft_atoi(argv[2]);
		if (d->iter <= 0)
			d->iter = INIT_ITER;
	}
	if ((argc > 5) && ((!ft_is_argdbl(argv[3])) || (!ft_is_argdbl(argv[4]))))
		return (ft_kill_werror("Invalid argument type\n"));
	else if (argc == 5)
	{
		d->c_julia.r = ft_atod(argv[3]);
		d->c_julia.i = ft_atod(argv[4]);
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
