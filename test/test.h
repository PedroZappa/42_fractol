/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:09:00 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 12:03:01 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H 
# define TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

#define MAX_ITER 10

typedef struct s_fractal
{
	long double z_r;
	long double z_i;
	long double oldz_r;
	long double oldz_i;
	long double c_r;
	long double c_i;
	int			iter;
}				t_fractal;

#endif
