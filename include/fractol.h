/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:57:56 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/15 16:54:46 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H


# define FRACTOL_H

# include "../42_lib/src/libft/libft.h"
# include "../42_lib/src/get_next_line/get_next_line.h"
# include "../42_lib/src/ft_printf/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <stdint.h>

// Error codes
#define ERROR_MESSAGE "Incorrect input. \nPlease respect the following format: \"./fractol mandelbrot\" or \"./fractol julia <real> <imaginary>\".\n"

// Display
# define HEIGHT 800
# define WIDTH 800
# define MAXITERATIONS 50

int	exit_with_error(int n);

// structs

typedef struct	s_color
{
	uint32_t	red_color;
	uint32_t	green_color;
	uint32_t	blue_color;
}	t_color;

typedef struct	s_fractol
{
	char		*type;
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		escape;
	int			iterations;
	double		zoom;
	double		position_x;
	double		position_y;
	double		julia_x;
	double		julia_y;
	t_color		color;
	uint32_t	color_palette[MAXITERATONS];
}	t_fractol;

// initialize
void	init_fractol(t_fractol	*fractol);

// render image
void	show_fractol(t_fractol	*fractol);

#endif

