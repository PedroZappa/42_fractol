/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:50:18 by passunca          #+#    #+#             */
/*   Updated: 2024/02/02 12:24:07 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_opts(void)
{
	ft_perror_color("Usage: ./fractol [OPTION]\n", RED);
	return (0);
}

int ft_no_args(void)
{
	ft_perror("No arguments provided.\nHere are all the available options:\n");
	ft_opts();
	return (0);	
}

int ft_has_hflag(int argc, char **argv)
{
	int i;

	i = -1;
	while (++i < argc)
		if (ft_strncmp(argv[i], "-h", 2) == 0)
			return (1);
	return (0);
}
