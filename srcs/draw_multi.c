/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:44:23 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/19 17:01:27 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					set_pixel(t_mlx *mlx, int x, int y, t_rgba color)
{
	*(mlx->image->data + ((x + y * WIN_WIDTH))) = (*(int *)&color);
}

void					*draw_thread(void *cur_t)
{
	int					y;
	int					x;
	t_thread			*t;

	t = (t_thread *)cur_t;
	y = -1 + WIN_HEIGHT / THREADS * t->id;
	while (++y < WIN_HEIGHT / THREADS * (t->id + 1))
	{
		t->c.im = t->mlx->max_coord.im - y * t->mlx->factor.im;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			t->c.re = t->mlx->min_coord.re + x * t->mlx->factor.re;
			set_pixel(t->mlx, x, y,
				get_color(t->mlx->fractal->function(t->mlx, t->c), t->mlx));
		}
	}
	return (NULL);
}

void					draw_by_multi_threads(t_mlx *mlx)
{
	int					i;
	t_thread_args		*t;

	t = &(mlx->thr_args);
	mlx->factor = init_complex(
		(mlx->max_coord.re - mlx->min_coord.re) / (WIN_WIDTH - 1),
		(mlx->max_coord.im - mlx->min_coord.im) / (WIN_HEIGHT - 1));
	i = -1;
	while (++i < THREADS)
	{
		t->args[i].id = i;
		t->args[i].mlx = mlx;
		pthread_create(t->threads + i, NULL, draw_thread, &(t->args[i]));
	}
	while (i-- > 0)
		pthread_join(t->threads[i], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->ptr, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - WIN_WIDTH * 0.13,
												0, COLOR_SILVER, "Help - H");
}

void					clear_img(t_img *img)
{
	int					i;

	i = -1;
	while (++i < WIN_WIDTH * WIN_HEIGHT)
		img->data[i] = 0;
}

void					draw_help(t_mlx *mlx)
{
	clear_img(mlx->image);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->ptr, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, COLOR_SILVER,
		"Controls :");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 45, COLOR_SILVER,
		"Reset                    - R");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 75, COLOR_SILVER,
		"Color Shift              - C");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 105, COLOR_SILVER,
		"On/Off multithreading    - T");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 135, COLOR_SILVER,
		"Move                     - Arrows");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 165, COLOR_SILVER,
		"Zoom                     - Scroll");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 195, COLOR_SILVER,
		"Iterations               - +/-");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 225, COLOR_SILVER,
		"Julia Constant           - Mouse");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 255, COLOR_SILVER,
		"Mouse Lock               - Space");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 285, COLOR_SILVER,
		"Close Help               - H");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 315, COLOR_SILVER,
		"Exit                     - Esc");
}
