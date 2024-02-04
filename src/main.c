/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:49:55 by passunca          #+#    #+#             */
/*   Updated: 2024/02/04 10:43:59 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_display	display;

	if (argc < 2)
		return (ft_no_args());
	if (ft_args(&display, argc, argv) == 0)
		return (EXIT_FAILURE);
	// display.c_julia.r = ft_atod(argv[2]);
	// display.c_julia.i = ft_atod(argv[3]);
	ft_init_display(&display);
	ft_render(&display);
	mlx_loop(display.mlx_conn);
	exit(EXIT_SUCCESS);
}

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;
// 	t_display	display;
// 	t_img		img;
//
// 	display.mlx_conn = mlx_init();
// 	if (!display.mlx_conn)
// 		exit (1);
//
// 	display.mlx_win = mlx_new_window(display.mlx_conn,
// 						WIDTH, HEIGHT, "Fractol");
// 	if (!display.mlx_win)
// 	{
// 		mlx_destroy_display(display.mlx_conn);
// 		free(display.mlx_conn);
// 		exit (1);
// 	}
// 	img.img = mlx_new_image(display.mlx_conn, WIDTH, HEIGHT);
// 	img.pix = mlx_get_data_addr(img.img,
// 	 					&img.bpp, &img.line_len, &img.endian);
//
// 	mlx_key_hook(display.mlx_win, handle_input, &display);
//
// 	mlx_loop(display.mlx_conn);
//
// 	mlx_destroy_window(display.mlx_conn, display.mlx_win);
// 	mlx_destroy_display(display.mlx_conn);
// 	free(display.mlx_conn);
// 	exit(0);
// }
