/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pix_to_complex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:04:31 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/03 18:10:43 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	map(int x_px, int y_px, t_mlx *mlx)
{
	mlx->c.re = (x_px * (mlx->plan.rmax - mlx->plan.rmin) / W) + mlx->plan.rmin;
	mlx->c.im = (y_px * (mlx->plan.imax - mlx->plan.imin) / H) + mlx->plan.imin;
	return (mlx->c);
}
