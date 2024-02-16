/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:20:17 by passunca          #+#    #+#             */
/*   Updated: 2024/02/14 13:33:10 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//=============================================================================/
//								Variables                                      /
//=============================================================================/

// Messages
# define MSG_KILL	"Thanks for playing passunca\'s Fract\'ol!\n"

// Display Dimensions
# define HEIGHT			800
# define WIDTH			800
# define OFFSET_X		0.3
# define OFFSET_Y		0.3
# define SCALE_FACTOR	1.055

// Complex Math Inits
# define INIT_ITER	42
# define INIT_C_R	-0.5
# define INIT_C_I	0.27025
# define MIN_R		-2.0
# define MAX_R		2.0
# define NEWTON_ESC 0.000001

# define SETS		5
# define COLORS		0xFFFFFF
// Set IDs
# define MANDELBROT	0
# define JULIA		1
# define TRICORN	2
# define BURNING	3
# define NEWTON		4

//=============================================================================/
//								Librariy Headers                               /
//=============================================================================/

# include <stdio.h>						// EXIT_FAILURE, EXIT_SUCCESS
# include <stdlib.h>					// malloc(), free(), exit()
# include <unistd.h>					// write()
# include <X11/X.h>						// MLX library for Event codes
# include <X11/keysym.h>				// Keysym for event handling
# include <math.h>						// sqrt()

# include "../inc/libft/libft/libft.h"	// Libft library
# include "../inc/libft/ft_printf/ft_printf.h"
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
	char		*name;
	t_img		img;
	long		iter;
	double		escape;
	double		x_offset;
	double		y_offset;
	double		zoom;
	t_complex	z;
	t_complex	c;
	t_complex	c_julia;
	t_complex	z_newton;
	double		newton_esc;
	t_range		win_size;
	t_range		frac_range;
	t_range		color_iter;
	t_range		color_range;
	int			color;
}				t_display;

//=============================================================================/
//							Function Prototypes                                /
//=============================================================================/

/* ft_args.c */
int			ft_args(t_display *display, int argc, char **argv);
int			ft_select_fractal(t_display *display, int argc, char **argv);

/*	ft_help.c : Args handling & help functions */
int			ft_usage(void);
int			ft_no_args(void);

/* ft_mlx.c : MLX setup functions */
void		ft_init_display(t_display *display, char **argv);
void		ft_events_init(t_display *display);
void		ft_init_data(t_display *display, char **argv);
t_complex	ft_init_complex(double r, double i);
t_range		ft_init_range(double min, double max);

/*	ft_render.c : Rendering bitmap functions */
void		ft_render(t_display *display);
void		ft_select_set(t_display *d, int x, int y);
void		ft_put_pixel(t_img img, int x, int y, int color);

/*	ft_sets.c : Fractal set renderers */
void		render_mandelbrot(t_display *display, int x, int y);
void		render_julia(t_display *display, int x, int y);
void		render_tricorn(t_display *d, int x, int y);
void		render_burning(t_display *d, int x, int y);

/*	ft_sets_newton.c : Newton's set needed its own file */
void		render_newton(t_display *display, int x, int y);

/*	ft_events.c */
int			ft_handle_keys(int keysym, t_display *display);
int			ft_handle_mouse(int button, int x, int y, t_display *display);

/*	ft_kill.c : exit functions */
void		ft_clean_kill(t_display *display);
int			ft_kill_werror(char *str);
void		ft_kill_window(t_display *display);
int			ft_kill_handle(t_display *display);
void		ft_error(void);

/* ft_math.c : Useful math functions */
double		ft_map(double n, t_range to_scale, t_range scaled);

/* ft_utils.c : Useful utility functions */
int			ft_is_argint(char *arg);
int			ft_is_argdbl(char *arg);

/* ft_ui.c : UI rendering functionality */
void		ft_render_ui(t_display *d);

/*	ft_color.c : Color functions */
int			ft_color_newton(unsigned int root);

#endif
