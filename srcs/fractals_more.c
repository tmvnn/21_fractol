/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 15:21:04 by lbellona          #+#    #+#             */
/*   Updated: 2020/04/19 17:24:05 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		f_celtic_mandelbrot(t_mlx *mlx, t_complex c)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(c.re, c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < mlx->max_iter)
	{
		z = init_complex(
			fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + c.re,
			2.0 * z.re * z.im + c.im);
		iteration++;
	}
	return (iteration);
}

int		f_celtic_mandelbar(t_mlx *mlx, t_complex c)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(c.re, c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < mlx->max_iter)
	{
		z = init_complex(
			fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + c.re,
			-2.0 * z.re * z.im + c.im);
		iteration++;
	}
	return (iteration);
}

int		f_perpendicular_burning_ship(t_mlx *mlx, t_complex c)
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
			-2.0 * z.re * fabs(z.im) + c.im);
		iteration++;
	}
	return (iteration);
}
