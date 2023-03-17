/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:05:05 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/08 12:08:05 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_if_belongs(t_mlx *mlx)
{
	double		z_re;
	double		z_im;
	double		z_temp;
	t_complex	k;

	z_re = 0;
	z_im = 0;
	mlx->iter = 0;
	if (mlx->mlx_fract == 0)
	{
		k.re = mlx->ir;
		k.im = mlx->ig;
	}
	while (mlx->iter < MAX_ITER)
	{
		z_temp = z_re;
		z_re = (z_re * z_re - z_im * z_im) + mlx->c.re;
		z_im = (2 * z_temp * z_im) + mlx->c.im;
		if (sqrt(z_re * z_re + z_im * z_im) > 2)
			break ;
		mlx->iter++;
		if (mlx->mlx_fract == 0)
			mlx->c = k;
	}
	return (mlx->iter);
}

int	color(t_mlx *data, int x, int y)
{
	data->iter = check_if_belongs(data);
	if (data->iter)
		draw_pixel(&data->image, x, y, data->color.color_i * (data->iter));
	if (data->iter > 20 && data->iter <= 90)
		draw_pixel(&data->image, x, y, data->color.color_j * (data->iter));
	if (data->iter == 100)
		draw_pixel(&data->image, x, y, data->color.color_j * (data->iter));
	return (0);
}

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
