/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:38:11 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/15 16:54:19 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_colors(t_fractol *fractol)
{
	int		index;
	int		red;
	int		green;
	int		blue;
	double	gradient;

	index = 1;
	fractol.color_palette[0] = 0xFF;
	while (index < MAXITERATIONS)
	{
		gradient = (double)index / (MAXITERATIONS / 2);
		red = (int)(fractol.color.red_color * (1 - gradient) * gradient * gradient * gradient * 255);
		green = (int)(fractol.color.green_color * (1 - gradient) * (1 - gradient) * gradient * gradient * 255);
		blue = (int)(fractol.color.blue_color * (1 - gradient) * (1 - gradient) * (1 - gradient) * (1 - gradient) * 255);
		fractol.color_palette[i] = (red << 24) | (g << 16) | (b << 8) | 255;
		index++;
	}
}
