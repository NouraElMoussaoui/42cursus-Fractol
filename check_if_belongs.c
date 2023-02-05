/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_belongs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:04:35 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/05 13:58:30 by nel-mous         ###   ########.fr       */
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
		if (sqrt(z_re * z_re + z_im * z_im) > 4)
			break ;
		mlx->iter++;
		if (mlx->mlx_fract == 0)
			mlx->c = k;
	}
	return (mlx->iter);
}
