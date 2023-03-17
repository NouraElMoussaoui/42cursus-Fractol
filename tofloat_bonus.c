/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tofloat_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:04:18 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/09 10:31:25 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	to_int(char *str, int *i, int *sign, double *x)
{
	while ((str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
		(*i)++;
	if ((str[*i] == '-' || str[*i] == '+') && str[*i + 1])
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
	while (str[*i] && (str[*i] >= '0' && str[*i] <= '9') && str[*i] != '.')
	{
		*x = *x * 10 + str[*i] - '0';
		(*i)++;
	}
	if (str[*i] && str[*i] != '.')
		oops();
}

double	to_float(char *str)
{
	int		i;
	int		sign;
	double	x;
	double	f;

	i = 0;
	sign = 1;
	x = 0;
	f = 0.1;
	if (str[i] == ' ' && str[i + 1] == '\0')
		oops();
	to_int(str, &i, &sign, &x);
	if (str[i] == '.' && str[i + 1])
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		x = x + (str[i++] - '0') * f;
		f /= 10;
	}
	if (str[i] && str[i] != ' ')
		oops();
	return (x * sign);
}
