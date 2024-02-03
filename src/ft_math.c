/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:42:35 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 17:36:08 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	Scale's n from a range of (to_map.min to max) 
 *								to (scaled.min to scaled.max):
*	       (b - a)(x - min)
*	f(x) = ---------------- + a
*			  max - min
*	*/
double	ft_map(double n, t_range to_scale, t_range scaled)
{
	return (((scaled.max - scaled.min) * (n - to_scale.min) 
				/ to_scale.max - to_scale.min) + scaled.min);
}

/*	Sum two complex numbers
 *	*/
t_complex	ft_c_sum(t_complex c1, t_complex c2)
{
	return ((t_complex){(c1.r + c2.r), (c1.i + c2.i)});
}

/*	Squaring a complex number
 *		(a + bi)² = (a² - b²) + 2abi
 *
 *		c.r = ((c.r * c.r) - (c.i * c.i));
 *		c.i = (2 * a * bi);
* */
t_complex	ft_c_square(t_complex c)
{
	return ((t_complex){((c.r * c.r) - (c.i * c.i)), (2 * c.r * c.i)});
}
