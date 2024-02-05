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
	ft_printf("Usage:\n");
	ft_printf("\t./fractol <set> <iterations> <c.r> <c.i>\n");
	ft_printf("%s");
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
