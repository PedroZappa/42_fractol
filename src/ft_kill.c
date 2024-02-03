/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:29:52 by passunca          #+#    #+#             */
/*   Updated: 2024/02/03 21:01:50 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	ft_clean_kill(t_display *display)
{
	(void)display;
	return ;
}

void	ft_kill_werror(t_display *display)
{
	(void)display;
	return ;
}

void	ft_kill_window(t_display *display)
{
	(void)display;
	return ;
}

void	ft_kill_handle(t_display *display)
{
	mlx_destroy_window(display->mlx_conn, display->mlx_win);
	mlx_destroy_display(display->mlx_conn);
	free(display->mlx_conn);
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
