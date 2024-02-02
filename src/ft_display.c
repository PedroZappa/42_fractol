/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:46:00 by passunca          #+#    #+#             */
/*   Updated: 2024/02/02 17:18:41 by passunca         ###   ########.fr       */
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
		ft_malloc_error();
	display->mlx_win = mlx_new_window(display->mlx_conn, 
								WIDTH, HEIGHT, display->name);
	if (!display->mlx_win)
	{
		mlx_destroy_display(display->mlx_conn);
		free(display->mlx_conn);
		ft_malloc_error();
	}
	display->img = mlx_new_image(display->mlx_conn, WIDTH, HEIGHT);
	if (!display->img)
	{
		mlx_destroy_window(display->mlx_conn, display->mlx_win);
		mlx_destroy_display(display->mlx_conn);
		free(display->mlx_conn);
		ft_malloc_error();
	}
	display->img->img = mlx_get_data_addr(display->img->img, 
								&display->img->bpp, &display->img->line_len, 
								&display->img->endian);
	//	ft_events_init()
	//	ft_data_init()
}

/*	ft_render : Renders the fractal
 *
 *	*/
void	ft_render(t_display *display)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_pixel(display, x, y);
	}
	return ;
}

/*	ft_put_pixel : Puts a pixel to the display
 *		Initialize z.r and z.i to 0.0
 *		Scale pixel coordinates to fit the mandelbrot range:
 *			Scale x from the range (0 to WIDTH) to (-2.0 to 2.0) [left to right]
 *			Scale y from the range (0 to WIDTH) to (2.0 to -2.0) [top to bottom]
 *		Plug pixel coordinates into the Mandelbrot equation
 *			Compute z = z^2 + c
 *	*/
void	ft_pixel(t_display *display, int x, int y)
{
	t_complex	z;
	t_complex	c;

	z.r = 0.0;
	z.i = 0.0;
	c.r = ft_scale(x, 0.0, WIDTH, -2.0, 2.0);
	c.i = ft_scale(y, 0.0, HEIGHT, 2.0, -2.0);
}
