/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:04:53 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/09 10:15:40 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_mlx *mlx, char *av)
{
		mlx->plan.rmin = -2;
		mlx->plan.rmax = 2;
		mlx->plan.imin = -2;
		mlx->plan.imax = 2;
		mlx->color.color_i = 0xFFF579;
		mlx->color.color_j = 0xAABF4D;
		mlx->ptr = mlx_init();
		mlx->win = mlx_new_window(mlx->ptr, W, H, av);
		mlx->image.img = mlx_new_image(mlx->ptr, W, H);
		mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bp,
			&mlx->image.l_len, &mlx->image.endian);
}

void	args(t_mlx *mlx, int ac, char **av)
{
	if (ft_strcmp(av[1], "Mandelbrot") == 0 && ac == 2)
		mandelbrot(mlx);
	else if (ac == 4 && ft_strcmp(av[1], "Julia") == 0 && av[2][0] != '\0'
		&& av[3][0] != '\0' && av[2][0] != '.' && av[3][0] != '.')
	{
		if ((mlx->ir >= -2 && mlx->ir <= 2) && (mlx->ig >= -2 && mlx->ig <= 2))
			julia(mlx);
		else
			oops();
	}
	else
		oops();
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac == 2 || ac == 4)
	{
		if (ac == 4)
		{
			mlx.ir = to_float(av[2]);
			mlx.ig = to_float(av[3]);
		}
		init(&mlx, av[1]);
		args(&mlx, ac, av);
		hooks(mlx);
	}
	else
		oops();
}
