/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:05:05 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/03 12:12:57 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_mlx *data)
{
	int	x;
	int	y;

	x = 0;
	data->mlx_fract = 1;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			data->c = map(x, y, data);
			color(data, x, y);
			y++;
		}
		x++;
	}
}

void	julia(t_mlx *data)
{
	int	x;
	int	y;

	x = 0;
	data->mlx_fract = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			data->c = map(x, y, data);
			color(data, x, y);
			y++;
		}
		x++;
	}
}
