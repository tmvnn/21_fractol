/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:45:16 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/19 17:23:51 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			help(t_mlx *mlx)
{
	mlx->help_mode = !mlx->help_mode;
	if (mlx->help_mode)
		draw_help(mlx);
	else
		draw(mlx);
	return (1);
}

static void			f_move(t_mlx *mlx, int key)
{
	t_complex	delta;

	delta = init_complex(fabs(mlx->max_coord.re - mlx->min_coord.re),
		fabs(mlx->max_coord.im - mlx->min_coord.im));
	if (key == RIGHT_CODE)
	{
		mlx->min_coord.re -= delta.re * 0.05;
		mlx->max_coord.re -= delta.re * 0.05;
	}
	else if (key == LEFT_CODE)
	{
		mlx->min_coord.re += delta.re * 0.05;
		mlx->max_coord.re += delta.re * 0.05;
	}
	else if (key == DOWN_CODE)
	{
		mlx->min_coord.im += delta.im * 0.05;
		mlx->max_coord.im += delta.im * 0.05;
	}
	else if (key == UP_CODE)
	{
		mlx->min_coord.im -= delta.im * 0.05;
		mlx->max_coord.im -= delta.im * 0.05;
	}
}

int					handle_key(int key, t_mlx *mlx)
{
	key == ESC_CODE ? exit(0) : (void)0;
	if (!mlx->help_mode)
	{
		key == SPACE_CODE ?
			mlx->fractal->is_static = !mlx->fractal->is_static : (void)0;
		key == PLUS_CODE ? mlx->max_iter++ : (void)0;
		key == R_CODE ? fractal_init(mlx) : (void)0;
		key == T_CODE ? mlx->use_threads = !mlx->use_threads :
																		(void)0;
		key == MINUS_CODE && mlx->max_iter >= 0 ? mlx->max_iter-- : (void)0;
		key == C_CODE ? mlx->color_shift = (mlx->color_shift + 1) % 3 : (void)0;
		key == UP_CODE || key == DOWN_CODE || key == LEFT_CODE ||
			key == RIGHT_CODE ? f_move(mlx, key) : (void)0;
		draw(mlx);
	}
	if (key == H_CODE)
		return (help(mlx));
	return (0);
}
