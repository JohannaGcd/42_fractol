/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:38:11 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/15 17:38:50 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//TODO: ask chatgpt to explain these two functions (cf. stretch image to fit chat)
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
		red = (int)(fractol->color.red_color * (1 - gradient) * gradient * gradient * gradient * 255);
		green = (int)(fractol->color.green_color * (1 - gradient) * (1 - gradient) * gradient * gradient * 255);
		blue = (int)(fractol->color.blue_color * (1 - gradient) * (1 - gradient) * (1 - gradient) * (1 - gradient) * 255);
		fractol->color_palette[index] = (red << 24) | (green << 16) | (blue << 8) | 255;
		index++;
	}
}

void	shift_color_palette(t_fractol	*fractol)
{
	fractol->color.red_color += 0.5; //TODO:Play around with values
	fractol->color.green_color += 0.5;
	fractol->color.blue_color += 0.5;
	init_colors(fractol);
}
