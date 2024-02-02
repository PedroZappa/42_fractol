/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:42:35 by passunca          #+#    #+#             */
/*   Updated: 2024/02/02 16:51:50 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Rescale's a range of values
*
*	*/
double	ft_scale(double unscaled_n, double new_min, double new_max, 
				double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_n - old_min) 
				/ (old_max - old_min) + new_min);
}
