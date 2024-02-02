/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:46:00 by passunca          #+#    #+#             */
/*   Updated: 2024/02/02 16:57:42 by passunca         ###   ########.fr       */
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
			ft_put_pixel(display, x, y);
	}
	return ;
}

/*	ft_put_pixel : Puts a pixel to the display
 *		Scale the pixel to the display
 *	*/
void	ft_put_pixel(t_display *display, int x, int y)
{

}
