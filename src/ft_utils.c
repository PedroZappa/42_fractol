/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:37:55 by passunca          #+#    #+#             */
/*   Updated: 2024/02/04 12:06:20 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_is_argint(char *arg)
{
	while (ft_isspace(*arg))
		++arg;
	if (*arg && ((*arg == '-') || (*arg == '+')))
		++arg;
	if (!arg)
		return (0);
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		++arg;
	}
	return (1);
}

int	ft_is_argdbl(char *arg)
{
	int	found;
	while (ft_isspace(*arg))
		++arg;
	if (*arg && ((*arg == '-') || (*arg == '+')))
		++arg;
	if (!arg)
		return (0);
	found = 0;
	while (*arg)
	{
		if (!ft_isdigit(*arg) && (*arg != '.') && (*arg != ','))
			return (0);
		if ((*arg == '.') || ((*arg == ',') && (found = 1)))
			return (0);
		if ((*arg == '.') || (*arg == ','))
			found = 1;
		++arg;
	}
	return (1);
}
