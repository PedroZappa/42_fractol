/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:28:05 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 12:31:10 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int ft_abs(int n);

int main(int argc, char **argv)
{
	t_fractal f;
	int i;

	f.iter = MAX_ITER;
	f.escape_val = 2.0;
	f.oldz_r = 0.0;
	f.oldz_i = 0.0;

	if (argc == 3)
	{
		f.c_r = atof(argv[1]);
		f.c_i = atof(argv[2]);
	}
	else if (argc == 4)
	{
		f.c_r = atof(argv[1]);
		f.c_i = atof(argv[2]);
		f.iter = atof(argv[3]);
	}
	i = -1;
	while(++i < f.iter) 
	{
		// Store values from previous iteration
		f.oldz_r = f.c_r;
		f.oldz_i = f.c_i;
		// Calculate current iteration
		f.c_r = ((f.oldz_r * f.oldz_r) - (f.oldz_i * f.oldz_i)) + f.c_r;
		f.c_i = (2.0 * f.oldz_r * f.oldz_i) + f.c_i;
		printf("%d : (%Lf\t,  %Lf)\n", (i+1), f.c_r, f.c_i);
		if ((ft_abs(f.c_r) > f.escape_val) || (ft_abs(f.c_i) > f.escape_val))
			break;
	}
	return (0);
}

int ft_abs(int n)
{
	return ((n < 0) ? -n : n);
}
