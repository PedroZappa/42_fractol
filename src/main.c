/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:49:55 by passunca          #+#    #+#             */
/*   Updated: 2024/02/01 21:47:46 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_input_checker(int argc, char **argv);

int	main(int argc, char **argv)
{

	if (ft_input_checker(argc, argv))
	{
		// TODO
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	ft_input_checker(int argc, char **argv)
{
	char	*tolower;
	int		i;

	i = 0;
	tolower = argv[1];
	while (tolower[i])
	{
		if (ft_isalpha(tolower[i]))
			tolower[i] = ft_tolower(tolower[i]);
		++i;
	}

	if (((argc == 2) && !ft_strncmp(tolower, "mandelbrot", 10))
		|| ((argc == 4) && !ft_strncmp(tolower, "julia", 5)))
		return (1);
	return (0);
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
