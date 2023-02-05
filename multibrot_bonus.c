/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:01:43 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/05 10:05:34 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	check_multibrot(t_mlx *mlx)
{
	double		z_re;
	double		z_im;
	double		z_te;

	z_re = 0;
	z_im = 0;
	mlx->iter = 0;
	while (mlx->iter < MAX_ITER)
	{
		z_te = z_re;
		z_re = (z_re * z_re * z_re * z_re) + (z_im * z_im * z_im * z_im)
			-(6 * z_re * z_re * z_im * z_im) + mlx->c.re;
		z_im = 4 * z_te * z_im * (z_te * z_te - z_im * z_im) + mlx->c.im;
		if (sqrt(z_re * z_re + z_im * z_im) > 4)
			break ;
		mlx->iter++;
	}
	return (mlx->iter);
}

int	color_multibrot(t_mlx *data, int x, int y)
{
	data->iter = check_multibrot(data);
	if (data->iter)
		draw_pixels(&data->image, x, y, data->color.color_i * (data->iter));
	if (data->iter > 20 && data->iter <= 100)
		draw_pixels(&data->image, x, y, data->color.color_j * (data->iter));
	if (data->iter == 120)
		draw_pixels(&data->image, x, y, data->color.color_j * (data->iter));
	return (0);
}

void	multibrot(t_mlx *data)
{
	int	x;
	int	y;

	data->mlx_fract = 3;
	x = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			data->c = map_bonus(x, y, data);
			color_multibrot(data, x, y);
			y++;
		}
		x++;
	}
}
