/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:05:09 by nel-mous          #+#    #+#             */
/*   Updated: 2023/02/09 08:53:42 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include<mlx.h>
# include<math.h>
# include "Libft/libft.h"

# define MAX_ITER 120
# define W 1200
# define H 1200
# define KEY_ESC 53 
# define SCROLL_UP 4
# define SCROLL_DOWN 5

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
	double		ir;
	double		ig;
	int			iter;
	t_image		image;
	t_complex	c;
	t_plan		plan;
	t_color		color;
}				t_mlx;

int			check_if_belongs(t_mlx *mlx);
int			color(t_mlx *data, int x, int y);
void		mandelbrot(t_mlx *data);
void		julia(t_mlx *data);
void		zoom(int key, t_mlx *mlx);
int			mouse_check(int key, int x, int y, t_mlx *mlx);
int			keys_check(int key);
int			close_window(t_mlx *mlx);
void		hooks(t_mlx mlx);
void		draw_pixel(t_image *data, int x, int y, int color);
void		clear_window(t_mlx *mlx);
void		oops(void);
double		to_float(char *str);
t_complex	map(int x_px, int y_px, t_mlx *mlx);

#endif