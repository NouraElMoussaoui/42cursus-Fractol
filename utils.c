/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:46:16 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/08 09:51:19 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	map(int x_px, int y_px, t_mlx *mlx)
{
	mlx->c.re = (x_px * (mlx->plan.rmax - mlx->plan.rmin) / W) + mlx->plan.rmin;
	mlx->c.im = (y_px * (mlx->plan.imax - mlx->plan.imin) / H) + mlx->plan.imin;
	return (mlx->c);
}

void	draw_pixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bp / 8));
	*(unsigned int *)dst = color;
}

void	clear_window(t_mlx *mlx)
{
	ft_bzero(mlx->image.addr, W * H * 4);
	mlx_clear_window(mlx->ptr, mlx->win);
}

void	oops(void)
{
	write(1, "you entered the wrong parameters,", 33);
	write(1, "choose between the following ones:\n", 35);
	write(1, "1)Mandelbrot\n", 13);
	write(1, "2)Julia [Real] [Imaginary]\n", 27);
	exit(0);
}
