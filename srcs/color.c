/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 20:52:11 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/07 21:14:52 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgba		get_color(int iteration, t_mlx *mlx)
{
	t_rgba	color;
	double	dt;

	dt = (double)iteration / mlx->max_iter;
	color.a = 0;
	color.r = (uint8_t)(9 * (1 - dt) * pow(dt, 3) * 255);
	color.g = (uint8_t)(15 * pow((1 - dt), 2) * pow(dt, 2) * 255);
	color.b = (uint8_t)(8.5 * pow((1 - dt), 3) * dt * 255);
	return (color);
}