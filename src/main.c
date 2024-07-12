/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:11:28 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/12 15:15:30 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


int	exit_with_error(int n)
{
	if (n == 1)
		ft_putstr_fd(ERROR_MESSAGE, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		|| (argc == 2 && ft_strncmp(argv[1], "julia", 6) == 0))
	{
		ft_putstr_fd("Prompt OK", 1);
	}
	else
	{
		exit_with_error(1);
	}
	return (EXIT_SUCCESS);
}
