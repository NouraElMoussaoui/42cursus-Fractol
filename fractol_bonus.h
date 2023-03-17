/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:47:13 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/09 10:17:54 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include<mlx.h>
# include<math.h>
# include "Libft/libft.h"

# define MAX_ITER 120
# define W 1200
# define H 1200
# define KEY_ESC 53 
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_SHIFT 258
# define KEY_PLUS 69
# define KEY_MINUS 78

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
	double		ir;
	double		ig;
	t_image		image;
	t_complex	c;
	t_plan		plan;
	t_color		color;
}				t_mlx;

int			check_if_belongs(t_mlx *mlx);
int			color(t_mlx *data, int x, int y);
void		mandelbrot(t_mlx *data);
void		julia(t_mlx *data);
int			mouse_check(int key, int x, int y, t_mlx *mlx);
void		animation(int key, t_mlx *mlx);
void		julia_animation(int key, t_mlx *mlx);
int			keys_check(int key, t_mlx *mlx);
int			close_window(t_mlx *mlx);
void		hooks(t_mlx mlx);
void		draw_pixel(t_image *data, int x, int y, int color);
void		clear_window(t_mlx *mlx);
void		oops(void);
void		shift_colors(t_mlx *mlx);
t_complex	map(int x_px, int y_px, t_mlx *mlx);
void		zoom(int key, t_mlx *mlx);
void		keys_handling(int key, t_mlx *mlx);
void		move(int key, t_mlx *mlx);
int			check_tricorn(t_mlx *mlx);
int			colortricorn(t_mlx *data, int x, int y);
void		tricorn(t_mlx *data);
int			check_multibrot(t_mlx *mlx);
int			color_multibrot(t_mlx *data, int x, int y);
void		multibrot(t_mlx *data);
double		to_float(char *str);

#endif