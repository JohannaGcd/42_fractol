/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:47:10 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/17 18:01:04 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdlib.h>
#include <unistd.h>

void	display_error(void)
{
	ft_putstr_fd("Error!\nMLX failed\n", STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

// This function initialises fractal paramaters,
// setting default values for fractal computation.
void	fill_data(t_fractol *fractol)
{
	fractol->escape = 4;
	fractol->iterations = MAX_ITERATION;
	fractol->position_x = 0;
	fractol->position_y = 0;
	fractol->zoom = 1;
	fractol->color.red_color = 4;
	fractol->color.green_color = 3;
	fractol->color.blue_color = 2;
	init_colors(fractol);
}

// This function initialises the MLX window,
// creating an image and setting event hooks.
void	init_fractol(t_fractol	*fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, fractol->type, true);
	if (!fractol->mlx)
	{
		mlx_terminate(fractol->mlx);
		display_error();
	}
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img
		|| mlx_image_to_window(fractol->mlx, fractol->img, 0, 0) < 0)
	{
		mlx_close_window(fractol->mlx);
		mlx_terminate(fractol->mlx);
		display_error();
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_loop_hook(fractol->mlx, (void *)handle_keyboard_hooks, fractol);
	mlx_scroll_hook(fractol->mlx, &mouse_scroll_hook, fractol);
	show_fractol(fractol);
	fill_data(fractol);
}
