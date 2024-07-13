/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:11:28 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/13 14:02:47 by jguacide         ###   ########.fr       */
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
		fractol.mlx = mlx_init(800, 800, argv[1], true);
		if (!fractol.mlx)
			exit(EXIT_FAILURE);
		fractol.img = mlx_new_image(fractol.mlx, 800, 800);
		if (!fractol.img)
		{
			printf("failed to generate image");
			mlx_terminate(fractol.mlx);
			exit(EXIT_FAILURE);
		}
		mlx_image_to_window(fractol.mlx, fractol.img, 0, 0);
		mlx_put_pixel(fractol.img, 100, 10, 0xFF0000FF);
		printf("pixel drawn");
		mlx_loop(fractol.mlx);
		mlx_terminate(fractol.mlx);
	}
	else
	{
		exit_with_error(1);
	}

	return (EXIT_SUCCESS);
}
