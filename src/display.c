/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:21:58 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/17 17:46:54 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// This function initializes z and c depending on the type of fractol.
// For mandelbrot, z starts at 0.0 fir julia c is a fixed parameter.
void	check_type_fractal(t_complex_plane *z,
						t_complex_plane *c,
						t_fractol *fractol)
{
	if (ft_strncmp(fractol->type, "julia", 6) == 0)
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

// This function computes the number of iterations needed for each pixel.
// This allows us to "map" the fractol on the screen
// and to determine the color of each pixel,
// depending on whether it belongs to the fractal or not.
// if an iteration of z never diverges (within the bounds of MAX_ITERATION),
// meaning the value of z stays below or equal to 2, its color is black.
int	calculate_color_pixel(int x, int y, t_fractol *fractol)
{
	t_complex_plane	z;
	t_complex_plane	c;
	int				i;

	i = 0;
	z.x = (scale_to_window(x, -2.0, 2.0, WIDTH) * fractol->zoom)
		+ fractol->position_x;
	z.y = (scale_to_window(y, 2.0, -2.0, HEIGHT) * fractol->zoom)
		+ fractol->position_y;
	check_type_fractal(&z, &c, fractol);
	while (i < fractol->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape)
			return (i);
		i++;
	}
	return (MAX_ITERATION);
}

// This function orchestrates the rendering of the entire fractal.
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
