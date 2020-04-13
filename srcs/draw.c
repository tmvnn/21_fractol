/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:44:23 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/13 18:32:36 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					clean_img(t_img *image)
{
	ft_bzero(image->data, WIN_WIDTH * WIN_HEIGHT * image->bpp);
}

void					clear_img(t_img *img)
{
	int					i;

	i = -1;
	while (++i < WIN_WIDTH * WIN_HEIGHT)
		img->data[i] = 0;
}

void					set_pixel(t_mlx *mlx, int x, int y, t_rgba color)
{
	*(mlx->image->data + ((x + y * WIN_WIDTH))) = (*(int *)&color);
}

void					fill_image(t_mlx *mlx)
{
	int					y;
	int					x;
	t_rgba				color;
	
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		mlx->c.im = mlx->max_coord.im - y * mlx->factor.im;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			mlx->c.re = mlx->min_coord.re + x * mlx->factor.re;
			color = get_color(mlx->fractal->function(mlx, mlx->c), mlx);
			set_pixel(mlx, x, y, color);
			mlx->p_drawn++;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->ptr, 0, 0);
}

void					*draw_thread(void *cur_t)
{
	int					y;
	int					x;
	t_rgba				color;
	t_thread			*t;
	int					end;
	
	t = (t_thread *)cur_t;
	y = -1 + WIN_HEIGHT / THREADS * t->id;
	end = WIN_HEIGHT / THREADS * (t->id + 1);
	//printf("id = %d start(y) = %d end = %d\n", t->id, y, end);
	//if (t->id == 0 || t->id == 1)
	{
	while (++y < end)
	{
		t->c.im = t->mlx->max_coord.im - y * t->mlx->factor.im;
		//t->mlx->c.im = t->mlx->max_coord.im - y * t->mlx->factor.im;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			// if (x == 0)
			// 	printf("y = %d, x = %d, id = %d\n", y, x, t->id);
			t->c.re = t->mlx->min_coord.re + x * t->mlx->factor.re;
			//t->mlx->c.re = t->mlx->min_coord.re + x * t->mlx->factor.re;
			//t->mlx->c = init_complex(t->c.re, t->c.im);
			color = get_color(t->mlx->fractal->function(t->mlx, t->c), t->mlx);
			set_pixel(t->mlx, x, y, color);

			//printf("y = %d, x = %d\n", y, x);
			t->mlx->p_drawn++;
		}
	}
	//printf("y = %d, x = %d\n", y, x);
	}
	return (NULL);
}

void					draw(t_mlx *mlx)
{
	int					i;
	t_thread_args		*t;

	//printf("draw #%d \n", mlx->draw_count++);
	t = &(mlx->thr_args);
	mlx->factor = init_complex(
		(mlx->max_coord.re - mlx->min_coord.re) / (WIN_WIDTH - 1),
		(mlx->max_coord.im - mlx->min_coord.im) / (WIN_HEIGHT - 1));
	i = -1;
	while (++i < THREADS)
	{
		t->args[i].id = i;
		//printf("arg_id = %d\n", t->args[i].id);
		t->args[i].mlx = mlx;
		pthread_create(t->threads + i, NULL, draw_thread, &(t->args[i]));
	}
	while (i-- > 0)
		pthread_join(t->threads[i], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->ptr, 0, 0);
	//fill_image(mlx);
	//printf(" drawn_p = %d \n", mlx->p_drawn);
}


// void					draw(t_mlx *mlx)
// {
// 	int					i;
// 	//t_thread_args		t;

// 	mlx->factor = init_complex(
// 		(mlx->max_coord.re - mlx->min_coord.re) / (WIN_WIDTH - 1),
// 		(mlx->max_coord.im - mlx->min_coord.im) / (WIN_HEIGHT - 1));
// 	i = -1;
// 	while (++i < THREADS)
// 	{
// 		t.args[i].id = i;
// 		//printf("arg_id = %d\n", t.args[i].id);
// 		t.args[i].mlx = mlx;
// 		pthread_create(&(t.threads[i]), NULL, draw_thread, &(t.args[i]));
// 	}
// 	while (i-- > 0)
// 		pthread_join(t.threads[i], NULL);
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->ptr, 0, 0);
	
// 	//fill_image(mlx);
// }