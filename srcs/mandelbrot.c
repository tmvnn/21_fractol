/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 21:01:52 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/07 21:27:12 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				f_mandelbrot(t_mlx *mlx)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(mlx->c.re, mlx->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < mlx->max_iter)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + mlx->c.re,
			2.0 * z.re * z.im + mlx->c.im);
		iteration++;
	}
	//printf("iter = %d\n", iteration);
	return (iteration);
}