/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:20:17 by passunca          #+#    #+#             */
/*   Updated: 2024/02/05 20:31:08 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//=============================================================================/
//								Variables                                      /
//=============================================================================/

// Messages
# define MSG_KILL	"Thanks for playing with Fract\'ol!\n\tBuBye...\n"

// Display Dimensions
# define HEIGHT		800
# define WIDTH		800

// Complex Math Inits
# define INIT_ITER	42
# define INIT_C_R	-0.7
# define INIT_C_I	0.27015
# define MIN_R		-2.0
# define MAX_R		2.0
# define MIN_I		-2.0
# define MAX_I		2.0

// Set IDs
# define MANDELBROT	0
# define JULIA		1
# define NEWTON		2

//=============================================================================/
//								Librariy Headers                               /
//=============================================================================/

# include <stdio.h>						// EXIT_FAILURE, EXIT_SUCCESS
# include <stdlib.h>					// malloc(), free(), exit()
# include <unistd.h>					// write()
# include <X11/X.h>						// MLX library for Event codes
# include <X11/keysym.h>				// Keysym for event handling

# include "../inc/libft/libft/libft.h"	// Libft library
# include "../inc/mlx/mlx.h"			// MLX library

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
 *	bpp:		Bits per pixel
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

/*	Struct for passing a range into scaling function
 *	*/
typedef struct s_range
{
	double		min;
	double		max;
}				t_range;


/* X Environment Structure
 *	// MLX variables
 *		mlx_conn:	Stores pointer to the MLX connection
 * 		mlx_win:	Stores pointer to the MLX window
 *	// Image variables
 *		name:		Fractal Name
 * 		img:		Pointer to image struct data
 * 		iter:		Number of iterations; determines the depth of the fractal
 *		escape:		Escape radius (hypothenuse) to stop the iteration
 *		x_offset:	Sets how much to shift on x-axis
 *		y_offset:	Sets how much to shift on y-axis
 * 	// Math Vars
 *		z:			Complex number z
 *		c:			Complex number c
 *	*/
typedef struct s_display
{
	void		*mlx_conn;
	void		*mlx_win;
	int			width;
	int			height;
	int			set;
	char 		*name;
	t_img		img;
	long		iter;
	double		escape;
	double		x_offset;
	double		y_offset;
	double		zoom;
	t_complex	z;
	t_complex	z_old;
	t_complex	c;
	t_complex	c_julia;
	t_complex	min;
	t_complex	max;
	t_range	win_size;
	t_range	frac_range;
	t_range	color_iter;
	t_range	color_range;
}				t_display;

//=============================================================================/
//							Function Prototypes                                /
//=============================================================================/

/* ft_args.c */
int			ft_args(t_display *display, int argc, char **argv);
int			ft_select_fractal(t_display *display, int argc, char **argv);
int			ft_set_complex(t_display *display, int argc, char **argv);
int			ft_invalid_args(char *name);
int			ft_no_args(void);

/*	ft_help.c : Args handling & help functions */
int			ft_usage(void);
int			ft_no_args(void);
int			ft_help_flag(int argc, char **argv);

/* ft_mlx.c : MLX setup functions */
void		ft_init_display(t_display *display);
void		ft_init_data(t_display *display);
t_complex	ft_init_complex(double r, double i);
t_range		ft_init_range(double min, double max);

/*	ft_display.c : Display functions */
void		ft_render(t_display *display);
void		ft_get_pixel(t_display *display, int x, int y);
void		ft_put_pixel(t_img img, int x, int y, int color);

/*	ft_sets.c : Fractal set renderers */
void		render_mandelbrot(t_display *display);
void		render_julia(t_display *display);
void		render_newton(t_display *display);

/*	ft_events.c */
void		ft_events_init(t_display *display);
int			ft_handle_keys(int key, t_display *display);
int			ft_handle_mouse(int button, int x, int y, t_display *display);

/*	ft_zoom.c */
int			ft_zoom(int keycode, int x, int y, t_display *display);

/*	ft_kill.c : exit functions */
void		ft_clean_kill(t_display *display);
int			ft_kill_werror(char *str);
void		ft_kill_window(t_display *display);
int			ft_kill_handle(t_display *display);
void		ft_error(void);

/* ft_math.c : Useful math functions */
double		ft_map(double n, t_range to_scale, t_range scaled);
t_complex	ft_c_sum(t_complex c1, t_complex c2);
t_complex	ft_c_square(t_complex c);

/* ft_utils.c : Useful utility functions */
int			ft_is_argint(char *arg);
int			ft_is_argdbl(char *arg);

#endif
