/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:22:22 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/08 10:16:15 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mouse_check(int key, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (key == SCROLL_DOWN || key == SCROLL_UP)
	{
		clear_window(mlx);
		zoom(key, mlx);
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
	return (0);
}

int	keys_check(int key, t_mlx *mlx)
{
	if (key == KEY_RIGHT || key == KEY_UP || key == KEY_LEFT || key == KEY_DOWN)
		move(key, mlx);
	else if (key == KEY_SHIFT)
		shift_colors(mlx);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		julia_animation(key, mlx);
	else if (key == KEY_ESC)
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
