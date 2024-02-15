/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:49:17 by passunca          #+#    #+#             */
/*   Updated: 2024/02/14 14:44:46 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color_newton(t_display *d, unsigned root)
{
	(void)d;
	if (root == 1)
		return (HEX_RED);
	else if (root == 2)
		return (HEX_BLUE);
	else if (root == 3)
		return (HEX_YELLOW);
	return (HEX_WHITE);
}
