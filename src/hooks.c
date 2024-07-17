/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:16:53 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/17 14:30:33 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	change_type_fractol(t_fractol *fractol, int value)
{
	if (value == 1)
	{
		fractol->type = "mandelbrot";
		mlx_set_window_title(fractol->mlx, fractol->type);
	}
	/*else if (value == 2)
	{
		fractol->type = "julia";
		mlx_set_window_title(fractol->mlx, fractol->type);
	}*/ //TODO: implement julia
}

int	close_window(void	*input)
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
		fractol->position_y -= 0.1;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		fractol->position_y += 0.1;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
		fractol->position_x -= 0.1;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
		fractol->position_x += 0.1;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_1))
		change_type_fractol(fractol, 1);
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_2)) //TODO:check if switch to julia works fractol->position_x -= 0.1;
		change_type_fractol(fractol, 2);
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_ADD))
		shift_color_palette(fractol);
	show_fractol(fractol);
}

void	mouse_scroll_hook(double xdelta, double ydelta, void *parameter)
{
	t_fractol	*fractol;

	(void)xdelta;
	fractol = (t_fractol *)parameter;
	if (ydelta > 0)
		fractol->zoom *= 0.90;
	else if (ydelta < 0)
		fractol->zoom *= 1.10;
	show_fractol(fractol);
}
