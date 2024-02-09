/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:49:55 by passunca          #+#    #+#             */
/*   Updated: 2024/02/04 10:43:59 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_display	display;

	if (argc < 2)
		return (ft_no_args());
	else if (!ft_args(&display, argc, argv))
		exit(EXIT_FAILURE);
	ft_init_display(&display);
	ft_printf("Fract'ol: %s\n", display.name);
	ft_render(&display);
	mlx_loop(display.mlx_conn);
	exit(EXIT_SUCCESS);
}
