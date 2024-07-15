/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:21:58 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/15 17:52:45 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fractol.h"

// This function computes the number of iterations needed for each pixel
// to determine its color based on whether it belongs to the fractal or not.
int calculate_color_pixel(int x, int y, t_fractol *fractol)
{
	t_complex_plane	 a;
	t_complex_plane	 b;
	int	i;

	i = 0;
	a.x = (scale)



}

// This function orchestrates the rendering of the entire fractal image pixel by pixel.
void	show_fractol(t_fractol	*fractol)
{
	int	x;
	int	y;
	int	color_pixel;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color_pixel = calculate_color_pixel(x, y, fractol);
			if (color_pixel < MAX_ITERATION)
				mlx_put_pixel(fractol->img, x, y, fractol->color_palette[color_pixel % MAX_ITERATION]);
			else
			 	mlx_put_pixel(fractol->img, x, y, fractol->color_palette[0]);
			x++;
		}
		y++;
	}

}
