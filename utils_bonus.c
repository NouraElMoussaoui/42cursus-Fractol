/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:05:57 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/05 10:06:10 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex	map_bonus(int x_px, int y_px, t_mlx *mlx)
{
	mlx->c.re = (x_px * (mlx->plan.rmax - mlx->plan.rmin) / W) + mlx->plan.rmin;
	mlx->c.im = (y_px * (mlx->plan.imax - mlx->plan.imin) / H) + mlx->plan.imin;
	return (mlx->c);
}

void	draw_pixels(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bp / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->image.img);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
	return (0);
}
