/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:09:00 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 11:09:38 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H 
# define TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

#define MAX_ITER 90

typedef struct s_fractal
{
	long double c_x;
	long double c_y;
	long double z_old;
	long double z_new;
	long double x_real;
	long double y_imagi;
}				t_fractal;

#endif
