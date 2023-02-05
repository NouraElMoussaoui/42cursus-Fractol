/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:47:13 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/05 09:58:07 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <stdio.h>
# include<mlx.h>
# include<math.h>
# include <stdlib.h>
# include "Libft/libft.h"

# define MAX_ITER 120
# define W 1000
# define H 1000
# define KEY_ESC 53 
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_SHIFT 258

typedef struct s_plan
{
	double	rmin;
	double	rmax;
	double	imin;
	double	imax;
}				t_plan;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bp;
	int		l_len;
	int		endian;
}				t_image;

typedef struct s_complex
{
	double	im;
	double	re;
}	t_complex;

typedef struct s_color
{
	int	color_i;
	int	color_j;
}	t_color;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	int			mlx_fract;
	int			iter;
	t_image		image;
	t_complex	c;
	t_plan		plan;
	t_color		color;
}				t_mlx;

void		draw_pixels(t_image *data, int x, int y, int color);
t_complex	map_bonus(int x_px, int y_px, t_mlx *mlx);
int			close_window(t_mlx *mlx);
int			check_tricorn(t_mlx *mlx);
int			check_multibrot(t_mlx *mlx);
void		tricorn(t_mlx *data);
void		multibrot(t_mlx *data);
int			colortricorn(t_mlx *data, int x, int y);
int			color_multibrot(t_mlx *data, int x, int y);
int			check_mouse(int key, int x, int y, t_mlx *mlx);
void		handle_keys(int key, t_mlx *mlx);
void		zoombonus(int key, t_mlx *mlx);
int			check_keys(int key, t_mlx *mlx);

#endif