/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_in_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:04:49 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/05 10:43:21 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int key, t_mlx *mlx)
{
	double	scale;

	scale = 0.8;
	if (key == SCROLL_DOWN)
	{
		mlx->plan.rmax *= scale;
		mlx->plan.rmin *= scale;
		mlx->plan.imax *= scale;
		mlx->plan.imin *= scale;
	}
	if (key == SCROLL_UP)
	{
		mlx->plan.rmax /= scale;
		mlx->plan.rmin /= scale;
		mlx->plan.imax /= scale;
		mlx->plan.imin /= scale;
	}
}

int	mouse_check(int key, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (key == SCROLL_DOWN || key == SCROLL_UP)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		zoom(key, mlx);
		if (mlx->mlx_fract == 0)
			julia(mlx);
		else if (mlx->mlx_fract == 1)
			mandelbrot(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image.img, 0, 0);
	}
	return (0);
}
