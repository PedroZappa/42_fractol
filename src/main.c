/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:49:55 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 22:53:00 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_input_checker(int argc, char **argv);
void ft_set_checker(t_display *display, char *input_set);

int	main(int argc, char **argv)
{
	t_display	display;

	if (ft_input_checker(argc, argv))
	{
		display.name = argv[1];
		// display.c_julia.r = ft_atod(argv[2]);
		// display.c_julia.i = ft_atod(argv[3]);
		ft_init_display(&display);
		ft_render(&display);
		mlx_loop(display.mlx_conn);
		exit(EXIT_SUCCESS);
	}
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/*	Checks if the input arguments are valid
 *
 *		Converts argv[1] to lowercase
 *		Checks if the input is:
 *				mandelbrot & has 2 arguments
 *				julia & has 4 arguments
 *
 *	*/
int	ft_input_checker(int argc, char **argv)
{
	char	*tolower;
	int		i;

	if (argc != 2 && argc != 4)
		return (0);
	i = -1;
	tolower = argv[1];
	while (tolower[++i])
		if (ft_isalpha(tolower[i]))
			tolower[i] = ft_tolower(tolower[i]);
	if (((argc == 2) && !ft_strncmp(tolower, "mandelbrot", 10))
		|| ((argc == 4) && !ft_strncmp(tolower, "julia", 5)))
		return (1);
	return (0);
}

void ft_set_checker(t_display *display, char *input_set)
{
	if (ft_strncmp(input_set, "mandelbrot", 10) == 0)
		render_mandelbrot(display);
	else if (ft_strncmp(input_set, "julia", 5) == 0)
		render_julia(display);
	else
		ft_kill_werror(display);
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
