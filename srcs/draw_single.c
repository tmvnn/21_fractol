/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_single.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 23:20:45 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/21 16:34:26 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					draw(t_mlx *mlx)
{
	if (mlx->use_threads)
		draw_by_multi_threads(mlx);
	else
		draw_by_single_thread(mlx);
}

void					draw_by_single_thread(t_mlx *mlx)
{
	mlx->factor = init_complex(
		(mlx->max_coord.re - mlx->min_coord.re) / (WIN_WIDTH - 1),
		(mlx->max_coord.im - mlx->min_coord.im) / (WIN_HEIGHT - 1));
	fill_image(mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - WIN_WIDTH * 0.13, 0,
													COLOR_SILVER, "Help - H");
}

void					fill_image(t_mlx *mlx)
{
	int					y;
	int					x;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		mlx->c.im = mlx->max_coord.im - y * mlx->factor.im;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			mlx->c.re = mlx->min_coord.re + x * mlx->factor.re;
			set_pixel(mlx, x, y,
						get_color(mlx->fractal->function(mlx, mlx->c), mlx));
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->ptr, 0, 0);
}
