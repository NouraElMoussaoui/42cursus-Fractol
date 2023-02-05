/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:31:02 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/05 09:58:30 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	hooks(t_mlx mlx)
{
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.image.img, 0, 0);
	mlx_key_hook(mlx.win, check_keys, &mlx);
	mlx_mouse_hook(mlx.win, check_mouse, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_loop(mlx.ptr);
}

void	if_errors(void)
{
	write(1, "you entered the wrong parameters,", 33);
	write(1, "choose between the following ones:\n", 35);
	write(1, "1)tricorn\n", 13);
	write(1, "2)multibrot\n", 27);
	exit(0);
}

void	initialize(t_mlx *mlx, char *av)
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
		mlx->image.addr = mlx_get_data_addr(mlx->image.img,
			&mlx->image.bp, &mlx->image.l_len, &mlx->image.endian);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac == 2 || ac == 4)
	{
		initialize(&mlx, av[1]);
		if (ft_strncmp(av[1], "tricorn", ft_strlen(av[1])) == 0)
			tricorn(&mlx);
		else if (ft_strncmp(av[1], "multibrot", ft_strlen(av[1])) == 0)
			multibrot(&mlx);
		else
			if_errors();
		hooks(mlx);
	}
	else
		if_errors();
}
