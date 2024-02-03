/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:20:17 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 20:53:06 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//=============================================================================/
//								Variables                                      /
//=============================================================================/

// Display Dimensions
# define HEIGHT	 800
# define WIDTH	 800

//=============================================================================/
//								Librariy Headers                               /
//=============================================================================/

# include <stdio.h>						// EXIT_FAILURE, EXIT_SUCCESS
# include <stdlib.h>					// malloc(), free(), exit()
# include <unistd.h>					// write()
# include <math.h>						// Math functions
# include <X11/keysym.h>				// Keysym for event handling
# include <X11/X.h>						// Event Codes

# include "../inc/mlx/mlx.h"			// MLX library
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
 *	img:		Pointer to image struct
 *	pix:		Pointer to image pixel data
 *	bpp:		Bytes per pixel
 *	line_len:	Line length
 *	endian:		Endian
 *	*/
typedef struct s_img
{
	void	*img;
	char	*pix;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

/* X Environment Structure
 *	// MLX variables
 *		mlx_conn:	Stores pointer to the MLX connection
 * 		mlx_win:	Stores pointer to the MLX window
 *	// Image variables
 *		name:		Fractal Name
 * 		img:		Pointer to image struct data
 * 		iter:		Number of iterations; determines the depth of the fractal
 * 	 escape:		Escape radius (hypothenuse) to stop the iteration
 * 	// Math Vars
 *		z:			Complex number z
 *		c:			Complex number c
 *	*/
typedef struct s_display
{
	void		*mlx_conn;
	void		*mlx_win;
	char 		*name;
	t_img		img;
	long		iter;
	double		escape;
	t_complex	z;
	t_complex	z_old;
	t_complex	c;
}				t_display;

/*	Struct for passing a range into scaling function
 *	*/
typedef struct s_range
{
	double		min;
	double		max;
}				t_range;

//=============================================================================/
//							Function Prototypes                                /
//=============================================================================/

/* ft_mlx.c : MLX setup functions */
void		ft_init_display(t_display *display);
void		ft_init_data(t_display *display);

/*	ft_display.c : Display functions */
void		ft_render(t_display *display);
void		ft_get_pixel(t_display *display, int x, int y);
void		ft_put_pixel(t_img img, int x, int y, int color);

/*	ft_sets.c : Fractal set renderers */
void		render_mandelbrot(t_display *display);
void		render_julia(t_display *display);

/*	ft_events.c */
void		ft_events_init(t_display *display);
int			ft_handle_keys(int key, t_display *display);

/*	ft_help.c : Args handling & help functions */
int			ft_usage(void);
int			ft_no_args(void);
int			ft_has_hflag(int argc, char **argv);

/*	ft_kill.c : exit functions */
void		ft_clean_kill(t_display *display);
void		ft_kill_werror(t_display *display);
void		ft_kill_window(t_display *display);
void		ft_kill_handle(t_display *display);
void		ft_error(void);

/* ft_math.c : Useful math functions */
double		ft_map(double n, t_range to_scale, t_range scaled);
t_complex	ft_c_sum(t_complex c1, t_complex c2);
t_complex	ft_c_square(t_complex c);

#endif
