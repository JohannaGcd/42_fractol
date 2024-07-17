/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:15:10 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/17 17:53:19 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// This function adds two complex numbers,
// combining the current value z with the constant c
// (cf. iteration process to determine the boundaries of the fractal).
t_complex_plane	sum_complex(t_complex_plane z, t_complex_plane c)
{
	t_complex_plane	sum;

	sum.x = z.x + c.x;
	sum.y = z.y + c.y;
	return (sum);
}

// This function squares two complex numbers.
// This is part of the iteration process to generate fractals.
t_complex_plane	square_complex(t_complex_plane z)
{
	t_complex_plane	square;

	square.x = (z.x * z.x) - (z.y * z.y);
	square.y = 2 * z.x * z.y;
	return (square);
}

// This function converts pixel coordinates (on the screen)
// to fractal coordinates on the complex plane.
double	scale_to_window(int value,
					   double new_min_position,
					   double new_max_position,
					   int old_max_position)
{
	double	scaled_value;
	double	temp;

	temp = (new_max_position - new_min_position) * value;
	scaled_value = temp / old_max_position + new_min_position;
	return (scaled_value);
}
