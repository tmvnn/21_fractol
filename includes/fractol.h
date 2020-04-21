/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:03:04 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/21 20:46:59 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <stdint.h>

# define WIN_HEIGHT 700
# define WIN_WIDTH 700
# define FRACT_COUNT 7
# define THREADS 8
# define ITERATIONS 50
# define COLOR_SILVER 0xCCCCCC
# define ESC_CODE 53
# define SPACE_CODE 49
# define PLUS_CODE 24
# define MINUS_CODE 27
# define R_CODE 15
# define T_CODE 17
# define H_CODE 4
# define C_CODE 8
# define SCROLL_UP_CODE 4
# define SCROLL_DOWN_CODE 5
# define UP_CODE 126
# define DOWN_CODE 125
# define LEFT_CODE 123
# define RIGHT_CODE	124
# define ALPHA_BITS 0xFF000000
# define RED_BITS 0x00FF0000
# define GREEN_BITS 0x0000FF00
# define BLUE_BITS 0x000000FF

typedef struct			s_rgba
{
	uint8_t				b;
	uint8_t				g;
	uint8_t				r;
	uint8_t				a;
}						t_rgba;

typedef struct			s_complex
{
	double				re;
	double				im;
}						t_complex;

typedef struct			s_img
{
	int					*ptr;
	int					*data;
	int					bpp;
	int					step;
	int					endian;
}						t_img;

typedef struct s_mlx	t_mlx;

typedef struct			s_fractal
{
	char				*name;
	int					(*function)(t_mlx *mlx, t_complex c);
	int					is_static;
}						t_fractal;

typedef struct			s_thread
{
	int					id;
	t_complex			c;
	t_mlx				*mlx;
}						t_thread;

typedef struct			s_thread_args
{
	pthread_t			threads[THREADS];
	t_thread			args[THREADS];
}						t_thread_args;

struct					s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					max_iter;
	t_complex			max_coord;
	t_complex			min_coord;
	t_complex			factor;
	t_complex			c;
	t_complex			k;
	uint8_t				help_mode;
	uint8_t				use_threads;
	int					color_shift;
	t_img				*image;
	t_fractal			*fractal;
	t_thread_args		thr_args;
};

t_mlx					*mlx_window_img_init(t_mlx *mlx);
t_img					*del_image(t_mlx *mlx, t_img *image);
t_mlx					*mlx_delete(t_mlx *mlx);
int						mlx_delete_all(t_mlx *fr, int count);
t_complex				init_complex(double re, double im);
void					fractal_init(t_mlx *mlx);
void					draw(t_mlx *mlx);
void					draw_by_multi_threads(t_mlx *mlx);
void					*draw_thread(void *cur_t);
void					draw_by_single_thread(t_mlx *mlx);
void					fill_image(t_mlx *mlx);
void					set_pixel(t_mlx *mlx, int x, int y, t_rgba color);
t_rgba					get_color(int iteration, t_mlx *mlx);
void					draw_help(t_mlx *mlx);
void					clear_img(t_img *img);
int						handle_key(int key, t_mlx *mlx);
int						zoom_change(int key, int x, int y, t_mlx *mlx);
int						julia_mouse_move(int x, int y, t_mlx *mlx);
int						f_mandelbrot(t_mlx *mlx, t_complex c);
int						f_celtic_mandelbrot(t_mlx *mlx, t_complex c);
int						f_julia(t_mlx *mlx, t_complex c);
int						f_burningship(t_mlx *mlx, t_complex c);
int						f_perpendicular_burning_ship(t_mlx *mlx, t_complex c);
int						f_mandelbar(t_mlx *mlx, t_complex c);
int						f_celtic_mandelbar(t_mlx *mlx, t_complex c);
int						pr_out(char *out_str);
int						usage_out(void);

#endif
