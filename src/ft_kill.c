/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:29:52 by passunca          #+#    #+#             */
/*   Updated: 2024/02/02 16:30:23 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	ft_window_kill(t_display *display)
{
	(void)display;
	return ;
}

/* Wrapper for perror() for malloc errors
 * Prints a string to stderr plus the error message from errno variable
 *
 * */
void	ft_malloc_error(void)
{
	perror("Malloc Error:");
	exit(EXIT_FAILURE);
}
