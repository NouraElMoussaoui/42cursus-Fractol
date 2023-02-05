/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:46:10 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/04 11:31:38 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bp / 8));
	*(unsigned int *)dst = color;
}

int	color(t_mlx *data, int x, int y)
{
	data->iter = check_if_belongs(data);
	if (data->iter)
		draw_pixel(&data->image, x, y, data->color.color_i * (data->iter));
	if (data->iter > 20 && data->iter <= 100)
		draw_pixel(&data->image, x, y, data->color.color_j * (data->iter));
	if (data->iter == 120)
		draw_pixel(&data->image, x, y, data->color.color_j * (data->iter));
	return (0);
}
