/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:43:59 by jguacide          #+#    #+#             */
/*   Updated: 2024/07/17 16:57:58 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// These functions are necessary to convert Julia arguments.

// This function allows us to adjust the sign of the result if it's a negative value
int	check_sign(char c)
{
	if (c == '-')
		return (-1.0);
	return (1.0);
}

// This function translates the fractional part of the number.
// The variable tenth allows us to scale the fractional digits.
double	atodouble_fractional(double temp_result, char *str, double sign)
{
	double	tenth;
	double	final_result;
	int	i;

	i = 0;
	tenth = 1.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp_result = (temp_result * 10.0) + (str[i] - '0');
		tenth *= 10.0;
		i++;
	}
	final_result = sign * temp_result / tenth;
	if (final_result > 2 || final_result < -2)
		exit_with_error(2);
	return (final_result);
}

// This function is like atoi, except it converts a string to a double.
// If a decimal point is encountered, it delegates the conversion of the fractional part to atodouble_fractional.
double	atodouble(char *str)
{
	int	i;
	double	sign;
	double	temp_result;
	double	final_result;

	i = 0;
	sign = 1.0;
	temp_result = 0.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = check_sign(str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp_result = (temp_result * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	final_result = atodouble_fractional(temp_result, &str[i], sign);
	return (final_result);
}

