/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:20:17 by passunca          #+#    #+#             */
/*   Updated: 2024/02/02 12:37:45 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT	 800
# define WIDTH	 800

//=============================================================================/
//								Librariy Headers                               /
//=============================================================================/

# include <stdio.h>				// EXIT_FAILURE, EXIT_SUCCESS
# include <stdlib.h>			// malloc(), free(), exit()
# include <unistd.h>			// write()
# include <math.h>				// Math functions
# include <X11/keysym.h>		// Keysym for event handling

# include "../inc/mlx/mlx.h"	// MLX library
# include "../inc/libft/libft/libft.h"	// Libft library

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

/* X Environment Structure
 *	mlx_conn:	Stores pointer to the MLX connection
 *	mlx_win:	Stores pointer to the MLX window
 *	*/
typedef struct s_env
{
	void		*mlx_conn;
	void		*mlx_win;
	int			size_x;
	int			size_y;
	int			type;
	long		iter;
	t_complex	c;
	t_complex	z;
	t_img		*img;
}				t_env;

//=============================================================================/
//							Function Prototypes                                /
//=============================================================================/

/* ft_events.c */
int	handle_input(int key, t_env *display);

/* ft_help.c */
int	ft_usage(void);
int ft_no_args(void);
int ft_has_hflag(int argc, char **argv);

/* ft_sets.c */
void	render_mandelbrot(t_env *env);
void	render_julia(t_env *env);

/* ft_kill.c */
void	ft_clean_kill(t_env *env);
void	ft_kill_werror(t_env *env);
void	ft_window_kill(t_env *env);

#endif
