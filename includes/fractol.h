/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:03:04 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/02 19:52:27 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <errno.h>
# include <math.h>

# define WIN_HEIGHT 700
# define WIN_WIDTH 700
# define POINT_COLOR 0xFFFFFF

typedef	struct		s_color
{
	uint8_t			channel[4];
}					t_color;

typedef struct		s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}					t_rgba;

typedef struct			s_img
{
	int					*ptr;
	char				*data;
	int					bpp;
	int					step;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct		s_fractal
{
	char				*name;
	//t_func_v			viewport;
	//t_func_p			pixel;
	int					is_mouse;
}					t_fractal;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					width;
	int					height;
	int					color;
	t_img				*image;
	t_fractal			*fractal;
}						t_mlx;

t_mlx 					*mlx_window_img_init(t_mlx *mlx);
t_img					*del_image(t_mlx *mlx, t_img *image);
t_mlx					*mlx_delete(t_mlx *mlx);

void					draw(t_mlx *mlx);
void					clear_img(t_img *image);
void					clean_img(t_img *img);
int						handle_key(int key, t_mlx *mlx);

#endif