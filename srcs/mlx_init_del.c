/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 13:43:30 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/01 18:43:15 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx			*mlx_delete(t_mlx *mlx)
{
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->image != NULL)
		del_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
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
	image->data = mlx_get_data_addr(image->ptr, &(image->bpp),
									&(image->step), &(image->endian));
	image->bpp /= 8;
	return (image);
}

t_mlx			*mlx_window_img_init(t_mlx *mlx)
{
	char		*heading;

	heading = ft_strjoin("Fract'ol ", mlx->fractal->name);
	if (!(mlx->mlx_ptr = mlx_init()) || !(mlx->image = new_image(mlx)))
		return (mlx_delete(mlx));
	mlx->width = WIN_WIDTH;
	mlx->height = WIN_HEIGHT;
	mlx->color = POINT_COLOR;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width,
														mlx->height, heading);
	free(heading);
	return (mlx);
}