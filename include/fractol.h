/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:57:56 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/12 17:40:37 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H


# define FRACTOL_H

# include "../42_lib/src/libft/libft.h"
# include "../42_lib/src/get_next_line/get_next_line.h"
# include "../42_lib/src/ft_printf/ft_printf.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>

// Error codes
#define ERROR_MESSAGE "Incorrect input. \nPlease respect the following format: \"./fractol mandelbrot\" or \"./fractol julia <real> <imaginary>\".\n"

// Display
#define HEIGHT 500
#define WIDTH 500

int	exit_with_error(int n);

// structs

typedef struct	t_fractol
{
		

}	s_fractol;

#endif

