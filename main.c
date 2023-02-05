/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:04:53 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/04 11:40:26 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook(t_mlx mlx)
{
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.image.img, 0, 0);
	mlx_key_hook(mlx.win, keys_check, &mlx);
	mlx_mouse_hook(mlx.win, mouse_check, &mlx);
	mlx_hook(mlx.win, 17, 0, close_win, &mlx);
	mlx_loop(mlx.ptr);
}

void	if_error(void)
{
	write(1, "you entered the wrong parameters,", 33);
	write(1, "choose between the following ones:\n", 35);
	write(1, "1)mandelbrot\n", 13);
	write(1, "2)julia [Real] [Imaginary]\n", 27);
	exit(0);
}

void	init(t_mlx *mlx, char *av)
{
		mlx->plan.rmin = -2;
		mlx->plan.rmax = 2;
		mlx->plan.imin = -2;
		mlx->plan.imax = 2;
		mlx->ptr = mlx_init();
		mlx->color.color_i = 0xFFF579;
		mlx->color.color_j = 0xAABF4D;
		mlx->win = mlx_new_window(mlx->ptr, W, H, &av[1]);
		mlx->image.img = mlx_new_image(mlx->ptr, W, H);
		mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bp,
			&mlx->image.l_len, &mlx->image.endian);
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
		if (ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])) == 0)
			mandelbrot(&mlx);
		else if (ft_strncmp(av[1], "julia", ft_strlen(av[1])) == 0)
		{
			if ((mlx.ir >= -2 && mlx.ir <= 2) && (mlx.ig >= -2 && mlx.ig <= 2))
				julia(&mlx);
			else
				if_error();
		}
		else
			if_error();
		hook(mlx);
	}
	else
		if_error();
}
