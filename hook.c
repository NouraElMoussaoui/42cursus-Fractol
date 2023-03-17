/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:43:03 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/08 09:53:50 by nel-mous         ###   ########.fr       */
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
		clear_window(mlx);
		zoom(key, mlx);
		if (mlx->mlx_fract == 0)
			julia(mlx);
		else if (mlx->mlx_fract == 1)
			mandelbrot(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image.img, 0, 0);
	}
	return (0);
}

int	keys_check(int key)
{
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->image.img);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
	return (0);
}

void	hooks(t_mlx mlx)
{
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.image.img, 0, 0);
	mlx_key_hook(mlx.win, keys_check, &mlx);
	mlx_mouse_hook(mlx.win, mouse_check, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_loop(mlx.ptr);
}
