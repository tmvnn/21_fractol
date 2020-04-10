/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:32:26 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/10 17:15:07 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				julia_mouse_move(int x, int y, t_mlx *mlx)
{
	if (!mlx->fractal->is_static) //(!fractol->is_help && !fractol->is_julia_fixed)
	{
		mlx->k = init_complex(
			4 * ((double)x / WIN_WIDTH - 0.5),
			4 * ((double)(WIN_HEIGHT - y) / WIN_HEIGHT - 0.5));
		draw(mlx);
	}
	return (0);
}

static double	interpolate(double t0, double t1, double dt)
{
	return (t0 + ((t1 - t0) * dt));
}

int				zoom_change(int key, int x, int y, t_mlx *mlx)
{
	t_complex	mouse;
	double		delta;
	
	if (key == SCROLL_UP_CODE || key == SCROLL_DOWN_CODE)
	{
		mouse = init_complex(
			(double)x / (WIN_WIDTH / (mlx->max_coord.re - mlx->min_coord.re))
				+ mlx->min_coord.re,
			(double)y / (WIN_HEIGHT / (mlx->max_coord.im - mlx->min_coord.im))
				* -1 + mlx->max_coord.im);
		if (key == SCROLL_UP_CODE)
			delta = 1.0 / 0.90;
		else
			delta = 1.0 / 1.10;
		mlx->min_coord.re = interpolate(mouse.re, mlx->min_coord.re, delta);
		mlx->min_coord.im = interpolate(mouse.im, mlx->min_coord.im, delta);
		mlx->max_coord.re = interpolate(mouse.re, mlx->max_coord.re, delta);
		mlx->max_coord.im = interpolate(mouse.im, mlx->max_coord.im, delta);
		draw(mlx);
	}
	return (0);
}