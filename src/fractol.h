/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:20:17 by passunca          #+#    #+#             */
/*   Updated: 2024/01/31 11:01:20 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//=============================================================================/
//								Librariy Headers                               /
//=============================================================================/
# include <stdio.h>		// printf(), EXIT_FAILURE, EXIT_SUCCESS
# include <stdlib.h>	// malloc(), free()

//=============================================================================/
//                               Structures                                    /
//=============================================================================/

/* Complex Number Structure 
 *	r:	Real part
 *	i:	Imaginary part
 *	*/
typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

/* Display Structure
 *	mlx_conn:	Stores pointer to the MLX connection
 *	mlx_win:	Stores pointer to the MLX window
 *	*/
typedef struct s_display
{
	void	*mlx_conn;
	void	*mlx_win;
}				t_display;

/* Image Data Buffer Structure 
 * [ Stores image data coming from mlx_get_data_addr() ]
 *	img:		Pointer to image
 *	pix:		Pointer to image pixel data
 *	bpp:		Bytes per pixel
 *	endian:		Endian
 *	line_len:	Line length
 *	*/
typedef struct s_img
{
	void	*img;
	char	*pix;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

#endif
