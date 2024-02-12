/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:58:27 by passunca          #+#    #+#             */
/*   Updated: 2024/02/05 20:13:07 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	ft_init_display : Connects to the X server
 *		mlx_init() : Initializes the display connection;
 *		mlx_new_window() : Creates a new window;
 *		mlx_new_image() : Creates a new image;
 *		Setup event listening
 *	*/
void	ft_init_display(t_display *display)
{
	display->mlx_conn = mlx_init();
	if (!display->mlx_conn)
		ft_error();
	display->mlx_win = mlx_new_window
		(display->mlx_conn, WIDTH, HEIGHT, display->name);
	if (!display->mlx_win)
		ft_clean_kill(display);
	display->img.img = mlx_new_image(display->mlx_conn, WIDTH, HEIGHT);
	if (!display->img.img)
		ft_kill_window(display);
	display->img.pix = mlx_get_data_addr
		(display->img.img, &display->img.bpp, &display->img.line_len,
			&display->img.endian);
	ft_events_init(display);
	ft_init_data(display);
	ft_sep_color('#', '=', 40, GRN);
}

/*	ft_init_data : Initializes t_display's data
 *		Set display->escape to 4.0, c² (See Pythagorean theorem)
 *		Set display->iter to 420 iterations as a default
 *		Sets Initial x and y offset 0.0
 *		Set Zoom to 1 so it can be used as a factor in multiplications
 *	*/
void	ft_init_data(t_display *display)
{
	display->height = HEIGHT;
	display->width = WIDTH;
	display->name = display->name;
	display->escape = 4.0;
	display->x_offset = 0.0;
	display->y_offset = 0.0;
	display->zoom = -SCALE_FACTOR;
	display->z = ft_init_complex(0.0, 0.0);
	display->c = ft_init_complex(0.0, 0.0);
	display->win_size = ft_init_range(0, WIDTH);
	display->frac_range = ft_init_range(MIN_R, MAX_R);
	display->color_iter = ft_init_range(HEX_BLACK, INIT_ITER);
	display->color_range = ft_init_range(HEX_BLACK, HEX_WHITE);
}

t_complex	ft_init_complex(double r, double i)
{
	t_complex	c;

	c.r = r;
	c.i = i;
	return (c);
}

t_range	ft_init_range(double min, double max)
{
	t_range	r;

	r.min = min;
	r.max = max;
	return (r);
}
