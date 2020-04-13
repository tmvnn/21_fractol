/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:45:16 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/13 15:50:05 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					handle_key(int key, t_mlx *mlx)
{
	key == ESC_CODE ? exit(0) : (void)0;
	key == SPACE_CODE ? mlx->fractal->is_static = !mlx->fractal->is_static :
																	(void)0;
	key == PLUS_CODE ? mlx->max_iter++ : (void)0;
	key == MINUS_CODE && mlx->max_iter >= 0 ? mlx->max_iter-- : (void)0;
	//clear_img(mlx->image);
	//clear_img(mlx->image);
	draw(mlx);
	return (0);
}