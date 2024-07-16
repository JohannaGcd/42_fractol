/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:16:53 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/16 15:34:04 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	close_window(void	*input)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)input;
	mlx_terminate(fractol->mlx);
	exit(EXIT_SUCCESS);
}

void	handle_keyboard_hooks(void	*input)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)input;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
		fractol->position_y += 0.1;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		fractol->position_y += 0.1;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT)) //TODO: check if right left is + or -
		fractol->position_x += 0.1;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
		fractol->position_x -= 0.1;
	show_fractol(fractol);
}
