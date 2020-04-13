/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 21:01:52 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/13 18:30:06 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				f_mandelbrot(t_mlx *mlx, t_complex c)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(c.re, c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < mlx->max_iter)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
			2.0 * z.re * z.im + c.im);
		iteration++;
	}
	return (iteration);
}

int				f_julia(t_mlx *mlx, t_complex c)
{
	int			iteration;
	t_complex	z;

	c.re = c.re;
	iteration = 0;
	z = init_complex(mlx->c.re, mlx->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < mlx->max_iter)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + mlx->k.re,
			2.0 * z.re * z.im + mlx->k.im);
		iteration++;
	}
	return (iteration);
}

int				f_burningship(t_mlx *mlx, t_complex c)
{
	int			iteration;
	t_complex	z;

	c.re = c.re;
	iteration = 0;
	z = init_complex(mlx->c.re, mlx->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < mlx->max_iter)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + mlx->c.re,
			-2.0 * fabs(z.re * z.im) + mlx->c.im);
		iteration++;
	}
	return (iteration);
}
