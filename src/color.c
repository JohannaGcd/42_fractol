/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:38:11 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/16 15:46:57 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// This function sets up a color palette used to color the fractal based on the number of iterations.
// A color is represented by a 32 bit integer, with various shades of red, green and blue.
// The bit shifting operation ('<<') creates the final color by shifting each color component into ther respective positions in the integer.
void	init_colors(t_fractol *fractol)
{
	int		index;
	int		red;
	int		green;
	int		blue;
	double	gradient;

	index = 1;
	fractol->color_palette[0] = 0xFF;
	while (index < MAX_ITERATION)
	{
		gradient = (double)index / (MAX_ITERATION / 2);
		red = (int)(fractol->color.red_color * (1 - gradient) * gradient * 0.5 * 255);
		green = (int)(fractol->color.green_color * (1 - gradient) * (1 - gradient) * gradient * 0.5 * 255);
		blue = (int)(fractol->color.blue_color * (1 - gradient) * (1 - gradient) * gradient * 0.5 * 255);
		fractol->color_palette[index] = (red << 24) | (green << 16) | (blue << 8) | 255;
		index++;
	}
}

// TODO: what does this funciton do?
void	shift_color_palette(t_fractol *fractol)
{
	fractol->color.red_color += 0.1;
	fractol->color.green_color += 0.1;
	fractol->color.blue_color += 0.1;
	init_colors(fractol);
}
