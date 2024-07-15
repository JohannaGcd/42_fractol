/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:21:58 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/15 11:41:51 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fractol.h"

void	show_fractol(t_fractol	*fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			mlx_put_pixel(fractol->img, x, y, fractol->color.red);
		}
	}

}
