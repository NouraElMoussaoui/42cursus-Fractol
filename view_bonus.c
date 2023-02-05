/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:30:56 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/05 10:43:48 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	zoombonus(int key, t_mlx *mlx)
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

int	check_mouse(int key, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (key == SCROLL_DOWN || key == SCROLL_UP)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		zoombonus(key, mlx);
		if (mlx->mlx_fract == 2)
			tricorn(mlx);
		else if (mlx->mlx_fract == 3)
			multibrot(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image.img, 0, 0);
	}
	return (0);
}

void	handle_keys(int key, t_mlx *mlx)
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

int	check_keys(int key, t_mlx *mlx)
{
	if (key == KEY_RIGHT || key == KEY_UP || key == KEY_LEFT || key == KEY_DOWN)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		handle_keys(key, mlx);
		if (mlx->mlx_fract == 2)
			tricorn(mlx);
		else if (mlx->mlx_fract == 3)
			multibrot(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image.img, 0, 0);
	}
	else if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_SHIFT)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx->color.color_i += 5;
		mlx->color.color_j += 100;
		if (mlx->mlx_fract == 2)
			tricorn(mlx);
		else if (mlx->mlx_fract == 3)
			multibrot(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image.img, 0, 0);
	}
	return (0);
}
