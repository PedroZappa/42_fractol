/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:42:35 by passunca          #+#    #+#             */
/*   Updated: 2024/02/02 17:26:52 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	Scale's a range of values from 0 to max:
*	       (b-a)(x)
*	f(x) = -------- + a
*			  max
*	*/
double	ft_scale(double unscaled_n, double max,
				double scaled_min, double scaled_max)
{
	return (((scaled_max - scaled_min) * unscaled_n / max) + scaled_min);
}

/*	Sum two complex numbers
 *	*/
t_complex	ft_complex_sum(t_complex c1, t_complex c2)
{
	return ((t_complex){c1.r + c2.r, c1.i + c2.i});
}
