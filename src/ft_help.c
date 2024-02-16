/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:45:18 by passunca          #+#    #+#             */
/*   Updated: 2024/02/12 17:05:27 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_controls(void);

int	ft_usage(void)
{
	ft_sep_color('#', '=', 45, GRN);
	ft_pout_color(">> Fract'ol Usage <<\n", MAG);
	ft_sep_color('#', '=', 45, GRN);
	ft_pout_color("\tAvailable Sets\n", YEL);
	ft_sep_color('#', '=', 45, GRN);
	ft_printf("1: Mandelbrot\n\t%s./fractol mandelbrot <iter>%s\n", CYN, NC);
	ft_printf("2: Julia\n\t%s./fractol julia <iter> <c.r> <c.i>%s\n", CYN, NC);
	ft_printf("3: Tricorn\n\t%s./fractol tricorn <iter>%s\n", CYN, NC);
	ft_printf("4: Burning Ship\n\t%s./fractol burning <iter>%s\n", CYN, NC);
	ft_printf("5: Newton\n\t%s./fractol newton <iter>%s\n", CYN, NC);
	ft_controls();
	return (0);
}

static void	ft_controls(void)
{
	ft_sep_color('#', '=', 45, GRN);
	ft_pout_color("\tControls\n", YEL);
	ft_sep_color('#', '=', 45, GRN);
	ft_printf(":Move around with:\n\t> %sArrow keys%s\n", CYN, NC);
	ft_printf(":Zoom in and out with:\n\t> %sMouse wheel%s\n", CYN, NC);
	ft_printf(":Change n iterations with:\n\t> %sPageUp & PageDown%s\n",
		CYN, NC);
	ft_printf(":Change color scheme with:\n\t> %sL-Shift & R-Shift%s\n",
		CYN, NC);
	ft_printf(":Select a specific Set with:\n\t", CYN, NC);
	ft_printf("> %s1, 2, 3, 4, 5%s\n", CYN, NC);
	ft_printf(":To Exit press:\n\t> %sESC%s\n", CYN, NC);
	ft_sep_color('#', '=', 45, GRN);
}

int	ft_no_args(void)
{
	ft_perror_color("No arguments provided.\n", RED);
	ft_usage();
	exit(EXIT_FAILURE);
}
