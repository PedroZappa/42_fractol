/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:46:00 by passunca          #+#    #+#             */
/*   Updated: 2024/02/02 18:44:51 by passunca         ###   ########.fr       */
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
	display->mlx_win = mlx_new_window
		(display->mlx_conn, WIDTH, HEIGHT, display->name);
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
	display->img->img = mlx_get_data_addr
		(display->img->img, &display->img->bpp, &display->img->line_len,
			&display->img->endian);
	//	ft_events_init()
	ft_init_data(display);
}

/*	ft_init_data : Initializes the data
 *
 *	*/
void	ft_init_data(t_display *display)
{
	(void)display;
	return ;
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
			ft_get_pixel(display, x, y);
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
void	ft_get_pixel(t_display *display, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	i = -1;
	z.r = 0.0;
	z.i = 0.0;
	c.r = ft_scale(x, WIDTH, -2.0, 2.0);
	c.i = ft_scale(y, HEIGHT, 2.0, -2.0);
	while (++i < display->iter)
	{
		z = ft_complex_sum(ft_complex_square(z), c);
		if ((z.r * z.r) + (z.i * z.i) > 4.0)
		{
			color = ft_scale(i, HEX_WHITE, 0, display->iter);
			ft_put_pixel(display, x, y, color);
			return ;
		}
	}
}

/*	ft_put_pixel : Puts a pixel to the display
 *
 *	*/
void	ft_put_pixel(t_display *display, int x, int y, int color)
{
	(void)display;
	(void)x;
	(void)y;
	(void)color;
	return ;
}
