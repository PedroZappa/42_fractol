/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:58:27 by passunca          #+#    #+#             */
/*   Updated: 2024/02/04 12:08:46 by passunca         ###   ########.fr       */
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
	display->escape = 4.0;
	display->iter = INIT_ITER;
	display->height = HEIGHT;
	display->width = WIDTH;
	display->x_offset = 0.0;
	display->y_offset = 0.0;
	display->zoom = 1.5;
	display->z.r = 0;
	display->z.i = 0;
	display->z_old.r = 0;
	display->z_old.i = 0;
	display->c.r = 0;
	display->c.i = 0;
}
