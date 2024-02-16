/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:29:52 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 21:24:39 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	ft_clean_kill(t_display *display)
{
	ft_sep_color('#', '=', 40, GRN);
	mlx_destroy_display(display->mlx_conn);
	free(display->mlx_conn);
	ft_error();
}

int	ft_kill_werror(char *str)
{
	ft_sep_color('#', '=', 40, GRN);
	ft_perror_color(str, RED);
	ft_usage();
	return (0);
}

void	ft_kill_window(t_display *display)
{
	mlx_destroy_image(display->mlx_conn, display->img.img);
	mlx_destroy_window(display->mlx_conn, display->mlx_win);
	mlx_destroy_display(display->mlx_conn);
	free(display->mlx_conn);
	ft_error();
}

/*	Handles pressing of ESC key or the X on the GUI
 *	Needs to have the following prototype:
 *		int (*f)(void *param)
 *	*/
int	ft_kill_handle(t_display *display)
{
	ft_sep_color('#', '=', 40, GRN);
	ft_printf(MSG_KILL);
	mlx_destroy_image(display->mlx_conn, display->img.img);
	mlx_destroy_window(display->mlx_conn, display->mlx_win);
	mlx_destroy_display(display->mlx_conn);
	free(display->mlx_conn);
	// free(display->name);
	// free(display);
	exit(EXIT_SUCCESS);
}

/* Wrapper for perror() for malloc errors
 * Prints a string to stderr plus the error message from errno variable
 *
 * */
void	ft_error(void)
{
	perror("Error:");
	exit(EXIT_FAILURE);
}
