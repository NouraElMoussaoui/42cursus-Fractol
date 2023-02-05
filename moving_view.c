/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:04:18 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/05 10:35:47 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keys_handling(int key, t_mlx *mlx)
{	
	double	shift;

	shift = 0.3;
	if (key == KEY_LEFT)
	{
		mlx->plan.rmax += shift;
		mlx->plan.rmin += shift;
	}
	if (key == KEY_UP)
	{
		mlx->plan.imax += shift;
		mlx->plan.imin += shift;
	}
	if (key == KEY_RIGHT)
	{
		mlx->plan.rmax -= shift;
		mlx->plan.rmin -= shift;
	}
	if (key == KEY_DOWN)
	{
		mlx->plan.imax -= shift;
		mlx->plan.imin -= shift;
	}
}

int	keys_check(int key, t_mlx *mlx)
{
	if (key == KEY_RIGHT || key == KEY_UP || key == KEY_LEFT || key == KEY_DOWN)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		keys_handling(key, mlx);
		if (mlx->mlx_fract == 1)
			mandelbrot(mlx);
		else if (mlx->mlx_fract == 0)
			julia(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image.img, 0, 0);
	}
	else if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_SHIFT)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx->color.color_i += 5;
		mlx->color.color_j += 100;
		if (mlx->mlx_fract == 1)
			mandelbrot(mlx);
		else if (mlx->mlx_fract == 0)
			julia(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image.img, 0, 0);
	}
	return (0);
}
