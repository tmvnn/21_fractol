/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 13:43:30 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/21 16:18:20 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fractal_init(t_mlx *mlx)
{
	mlx->max_iter = ITERATIONS;
	mlx->min_coord = init_complex(-2.0, -2.0);
	mlx->max_coord.re = 2.0;
	mlx->max_coord.im = mlx->min_coord.im
		+ (mlx->max_coord.re - mlx->min_coord.re) * WIN_HEIGHT / WIN_WIDTH;
	mlx->k = init_complex(-0.4, 0.6);
	mlx->color_shift = 0;
	mlx->help_mode = 0;
	mlx->use_threads = 1;
}

t_mlx			*mlx_delete(t_mlx *mlx)
{
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->image != NULL)
		del_image(mlx, mlx->image);
	return (NULL);
}

t_img			*del_image(t_mlx *mlx, t_img *image)
{
	if (image != NULL)
	{
		if (image->ptr != NULL)
			mlx_destroy_image(mlx->mlx_ptr, image->ptr);
		ft_memdel((void **)&image);
	}
	return (NULL);
}

t_img			*new_image(t_mlx *mlx)
{
	t_img		*image;

	if (!(image = ft_memalloc(sizeof(t_img))))
		return (NULL);
	if (!(image->ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		return (del_image(mlx, image));
	image->data = (int*)mlx_get_data_addr(image->ptr, &(image->bpp),
									&(image->step), &(image->endian));
	image->bpp /= 8;
	return (image);
}

t_mlx			*mlx_window_img_init(t_mlx *mlx)
{
	char		*heading;

	heading = ft_strjoin("Fract'ol ", mlx->fractal->name);
	if (!(mlx->image = new_image(mlx)))
		return (NULL);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH,
													WIN_HEIGHT, heading)))
		return (mlx_delete(mlx));
	free(heading);
	return (mlx);
}
