/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:44:23 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/10 14:36:12 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					clean_img(t_img *image)
{
	ft_bzero(image->data, WIN_WIDTH * WIN_HEIGHT * image->bpp);
}

void					clear_img(t_img *img)
{
	int				i;

	i = -1;
	while (++i < WIN_WIDTH * WIN_HEIGHT)
		img->data[i] = 0;
}

void					set_pixel(t_mlx *mlx, int x, int y, t_rgba color)
{
	*(mlx->image->data + ((x + y * WIN_WIDTH))) = (*(int *)&color);
}

void					draw(t_mlx *mlx)
{
	int			y;
	int			x;
	t_rgba		color;
	
	mlx->factor = init_complex(
		(mlx->max_coord.re - mlx->min_coord.re) / (WIN_WIDTH - 1),
		(mlx->max_coord.im - mlx->min_coord.im) / (WIN_HEIGHT - 1));
	// color.a = 0;
	// color.r = 255;
	// color.g = 0;
	// color.b = 0;
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		mlx->c.im = mlx->max_coord.im - y * mlx->factor.im;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			mlx->c.re = mlx->min_coord.re + x * mlx->factor.re;
			color = get_color(mlx->fractal->function(mlx), mlx);
			set_pixel(mlx, x, y, color);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->ptr, 0, 0);
}