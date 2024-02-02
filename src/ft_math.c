/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:42:35 by passunca          #+#    #+#             */
/*   Updated: 2024/02/02 16:56:34 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Rescale's a range of values by applying the function:
*	       (b-a)(x - min)
*	f(x) = --------------  + a
*	          max - min
*	*/
double	ft_scale(double unscaled_n, double scaled_min, double scaled_max, 
				double min, double max)
{
	return (((scaled_max - scaled_min) * (unscaled_n - min) 
				/ (max - min)) + scaled_min);
}
