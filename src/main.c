/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:11:28 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/13 14:45:52 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdlib.h>


int	exit_with_error(int n)
{
	if (n == 1)
		ft_putstr_fd(ERROR_MESSAGE, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		|| (argc == 2 && ft_strncmp(argv[1], "julia", 6) == 0))
	{
		fractol.type = argv[1];
		init_fractol(&fractol);
		show_fractol(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
		exit_with_error(1);
	mlx_terminate(fractol.mlx);
	return (EXIT_SUCCESS);
}
