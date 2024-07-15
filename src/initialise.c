/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:47:10 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/15 12:01:52 by jguacide         ###   ########.fr       */
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

/*void	fill_data(t_fractol *fractol)
{
	fractol->color.red = 4;
}*/
void	init_fractol(t_fractol	*fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, fractol->type, true);
	if (!fractol->mlx)
	{
		mlx_terminate(fractol->mlx);
		display_error();
	}
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img || mlx_image_to_window(fractol->mlx, fractol->img, 0, 0) < 0)
	{
		mlx_close_window(fractol->mlx);
		mlx_terminate(fractol->mlx);
		display_error();
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	show_fractol(fractol);
	//fill_data(fractol);
}
