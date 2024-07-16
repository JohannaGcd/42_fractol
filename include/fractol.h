/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:57:56 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/16 15:34:17 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 800
# define WIDTH 800
# define MAX_ITERATION 50
# define ERROR_MESSAGE "Incorrect input. \nPlease respect the following format: \"./fractol mandelbrot\" or \"./fractol julia <real> <imaginary>\".\n"

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

int	exit_with_error(int n);

// structs

typedef struct	s_complex_plane
{
	double	x;
	double	y;
}	t_complex_plane;

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
	uint32_t	color_palette[MAX_ITERATION];
}	t_fractol;

// initialize
void	init_fractol(t_fractol	*fractol);

// render image
void	show_fractol(t_fractol	*fractol);
void	check_type_fractal(t_complex_plane *z, t_complex_plane *c, t_fractol *fractol);
int		calculate_color_pixel(int x, int y, t_fractol *fractol);

// math
t_complex_plane	sum_complex(t_complex_plane z, t_complex_plane c);
t_complex_plane	square_complex(t_complex_plane z);
double	scale_to_window(int value, double new_min_position, double new_max_position, int old_max_position);

// colors
void	init_colors(t_fractol *fractol);
void	shift_color_palette(t_fractol *fractol);

// handle events and hooks
void	handle_keyboard_hooks(void	*input);
void	close_window(void	*input);

#endif

