/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:03:04 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/10 18:04:58 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <pthread.h>

# define WIN_HEIGHT 700
# define WIN_WIDTH 700
# define THREADS 10
# define ITERATIONS 5

# define ESC_CODE 53
# define SPACE_CODE 49
# define PLUS_CODE 24
# define MINUS_CODE 27
# define SCROLL_UP_CODE 4
# define SCROLL_DOWN_CODE 5

// typedef	struct		s_color
// {
// 	uint8_t			channel[4];
// }					t_color;

typedef struct		s_rgba
{
	uint8_t				b;
	uint8_t				g;
	uint8_t				r;
	uint8_t				a;
}					t_rgba;

typedef struct		s_complex
{
	double				re;
	double				im;
}					t_complex;

typedef struct			s_img
{
	int					*ptr;
	int					*data;
	int					bpp;
	int					step;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct 			s_mlx	t_mlx;
typedef	int				(*fr_function)(t_mlx *mlx);

typedef struct			s_fractal
{
	char				*name;
	//t_func_v			viewport;
	//t_func_p			pixel;
	fr_function			function;
	int					is_static;
}						t_fractal;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					width;
	int					height;
	int					max_iter;
	t_complex			max_coord;
	t_complex			min_coord;
	t_complex			factor;
	t_complex			c;
	t_complex			k;
	int					color_shift;
	t_img				*image;
	t_fractal			*fractal;
}						t_mlx;

t_mlx 					*mlx_window_img_init(t_mlx *mlx);
t_img					*del_image(t_mlx *mlx, t_img *image);
t_mlx					*mlx_delete(t_mlx *mlx);
t_complex				init_complex(double re, double im);
void					fractal_init(t_mlx *mlx);

void					draw(t_mlx *mlx);
void					clean_img(t_img *image);
void					clear_img(t_img *img);
int						handle_key(int key, t_mlx *mlx);
int						zoom_change(int key, int x, int y, t_mlx *mlx);
int						pr_out(char *out_str);
void					*pr_error(char *err_msg);
void					set_pixel(t_mlx *mlx, int x, int y, t_rgba color);
t_rgba					get_color(int iteration, t_mlx *mlx);
int						f_mandelbrot(t_mlx *mlx);
int						f_julia(t_mlx *mlx);
int						julia_mouse_move(int x, int y, t_mlx *mlx);
int						f_burningship(t_mlx *mlx);

#endif