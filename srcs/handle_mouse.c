/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:32:26 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/10 14:33:44 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				julia_motion(int x, int y, t_mlx *mlx)
{
	//if (!fractol->is_help && !fractol->is_julia_fixed)
	{
		mlx->k = init_complex(
			4 * ((double)x / WIN_WIDTH - 0.5),
			4 * ((double)(WIN_HEIGHT - y) / WIN_HEIGHT - 0.5));
		draw_fractal(mlx);
	}
	return (0);
}