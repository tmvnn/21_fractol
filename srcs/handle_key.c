/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:45:16 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/16 23:38:16 by timuryakubo      ###   ########.fr       */
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
		draw(mlx);
	}
	if (key == H_CODE)
		return (help(mlx));
	return (0);
}