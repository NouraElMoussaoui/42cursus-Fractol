/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:30:56 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/08 12:23:37 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

void	move(int key, t_mlx *mlx)
{
	clear_window(mlx);
	keys_handling(key, mlx);
	if (mlx->mlx_fract == 1)
		mandelbrot(mlx);
	else if (mlx->mlx_fract == 0)
		julia(mlx);
	else if (mlx->mlx_fract == 2)
		tricorn(mlx);
	else if (mlx->mlx_fract == 3)
		multibrot(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image.img, 0, 0);
}

void	animation(int key, t_mlx *mlx)
{
	if (key == KEY_PLUS)
	{
		mlx->ir += 0.01;
		mlx->ig += 0.01;
	}
	else if (key == KEY_MINUS)
	{
		mlx->ir -= 0.01;
		mlx->ig -= 0.01;
	}
}

void	julia_animation(int key, t_mlx *mlx)
{
	clear_window(mlx);
	animation(key, mlx);
	if (mlx->mlx_fract == 1)
		mandelbrot(mlx);
	else if (mlx->mlx_fract == 0)
		julia(mlx);
	else if (mlx->mlx_fract == 2)
		tricorn(mlx);
	else if (mlx->mlx_fract == 3)
		multibrot(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image.img, 0, 0);
}
