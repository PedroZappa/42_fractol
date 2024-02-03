/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:42:35 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 22:12:20 by passunca         ###   ########.fr       */
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
				/ (to_scale.max - to_scale.min)) + scaled.min);
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
/*
int main(int argc, char **argv)
{
	double n = 5;
	double new_n;
	t_range to_scale;
	t_range scaled;

	if (argc != 6)
	{
		printf("Usage : ./a.out n min max newmin newmax\n");
		exit(1);
	}
	n = atof(argv[1]);
	to_scale.min = atof(argv[2]);
	to_scale.max = atof(argv[3]);
	scaled.min = atof(argv[4]);
	scaled.max =  atof(argv[5]);
	printf("n = %f\n", n);
	printf("to_scale %f -> %f\n", to_scale.min, to_scale.max);
	printf("scaled %f -> %f\n", scaled.min, scaled.max);
	new_n = ft_map(n, to_scale, scaled);
	printf("new_n = %f\n", new_n);
}
*/
