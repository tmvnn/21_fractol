/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:03:05 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/02 20:00:18 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					*pr_error(char *err_msg)
{
	perror(err_msg);
	exit(1);
}

int						pr_out(char *out_str)
{
	ft_putstr(out_str);
	return(1);
}

t_fractal				*get_fract_params()
{
	static t_fractal 	fract_params[4] = {
		{"mandelbrot", 0},
		{"julia", 1},
		{"burningship", 0},
		{NULL, 0}
	};
	return (fract_params);
}

t_fractal				*is_fractal(char *str)
{
	t_fractal			*f;
	int					i;

	f = get_fract_params();
	i = -1;
	while (f[++i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
	}
	return (NULL);
}

int					handle_key(int key, t_mlx *mlx)
{
	key == 53 ? exit(0) : (void)0;
	//clear_img(mlx->image);
	//clean_img(mlx->image);
	draw(mlx);
	return (0);
}

void					draw(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->ptr, 0, 0);
}

void					clear_img(t_img *image)
{
	ft_bzero(image->data, WIN_WIDTH * WIN_HEIGHT * image->bpp);
}

void					clean_img(t_img *img)
{
	int				i;

	i = -1;
	while (++i < img->width * img->height)
		img->data[i] = 0;
}

int						main(int argc, char **argv)
{
	t_mlx				mlx;
	
	errno = 0;
	if (argc != 2)
		return(pr_out("Usage : ./fractol <fract_name>\n"));
	if (!(mlx.fractal = is_fractal(argv[1])))
		return(pr_out("Error : invalid fractal name\n"));
	if (!(mlx_window_img_init(&mlx)))
		return(pr_out("Error : could not initialize mlx\n"));
	//printf("%s\n", mlx.fractal->name);
	//render("Program was started\n");
	
	// mlx.image->data[1 + WIN_WIDTH * mlx.image->bpp] = -120;
	// mlx.image->data[2 + WIN_WIDTH * mlx.image->bpp] = -120;
	// mlx.image->data[3 + WIN_WIDTH * mlx.image->bpp] = -120;
	// mlx.image->data[4 + WIN_WIDTH * mlx.image->bpp] = 0;
	
	t_color color;
	color.channel[3] = 0;
	color.channel[2] = 0;
	color.channel[1] = 0;
	color.channel[0] = 255;
	printf("num = %d\n", (int)(POINT_COLOR));
	printf("num = %d\n", (*(int *)color.channel)); //(int)(*(int *)result)
	int y = -1;
	while (++y < WIN_HEIGHT)
	{
		int x = -1;
		while (++x < WIN_WIDTH)
		{
			*(int *)(mlx.image->data + ((x + y * WIN_WIDTH) * mlx.image->bpp)) = (*(int *)color.channel);
		}
	}
		
	
	printf("rgbs_size = %lu\n", sizeof(t_rgba));
	printf("rgbs_size = %lu\n", sizeof(t_color));
	draw(&mlx);
	//mlx_expose_hook(mlx.win_ptr, handle_key, &mlx);
	mlx_hook(mlx.win_ptr, 2, 0, handle_key, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}