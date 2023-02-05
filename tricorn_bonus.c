/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:55:39 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/05 10:35:02 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	check_tricorn(t_mlx *mlx)
{
	double	z_re;
	double	z_im;
	double	z_temp;

	z_re = 0;
	z_im = 0;
	mlx->iter = 0;
	while (mlx->iter < MAX_ITER)
	{
		z_temp = z_re;
		z_re = (z_re * z_re - z_im * z_im) + mlx->c.re;
		z_im = (-2 * z_temp * z_im) + mlx->c.im;
		if (sqrt(z_re * z_re + z_im * z_im) > 4)
			break ;
		mlx->iter++;
	}
	return (mlx->iter);
}

int	colortricorn(t_mlx *data, int x, int y)
{
	data->iter = check_tricorn(data);
	if (data->iter)
		draw_pixels(&data->image, x, y, data->color.color_i * (data->iter));
	if (data->iter > 20 && data->iter < 900)
		draw_pixels(&data->image, x, y, data->color.color_j * (data->iter));
	if (data->iter == 1000)
		draw_pixels(&data->image, x, y, data->color.color_j * (data->iter));
	return (0);
}

void	tricorn(t_mlx *data)
{
	int	x;
	int	y;

	data->mlx_fract = 2;
	x = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			data->c = map_bonus(x, y, data);
			colortricorn(data, x, y);
			y++;
		}
		x++;
	}
}
