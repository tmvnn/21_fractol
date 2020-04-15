/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 20:52:11 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/16 00:26:19 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgba		move_color(t_mlx *mlx, int c)
{
	int	i;

	i = -1;
	while(++i < mlx->color_shift)
		c = (c & ALPHA_BITS) | (c & RED_BITS) >> 8 | (c & GREEN_BITS) >> 8 | (c & BLUE_BITS) << 16;
	return ((*(t_rgba *)&c));
}

t_rgba		get_color(int iteration, t_mlx *mlx)
{
	t_rgba	color;
	double	dt;

	dt = (double)iteration / mlx->max_iter;
	color.a = 0;
	color.r = (uint8_t)(9 * (1 - dt) * pow(dt, 3) * 255);
	color.g = (uint8_t)(15 * pow((1 - dt), 2) * pow(dt, 2) * 255);
	color.b = (uint8_t)(8.5 * pow((1 - dt), 3) * dt * 255);
	return (move_color(mlx, (*(int *)&color)));
}