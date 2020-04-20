/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:03:05 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/19 17:28:15 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractal		*get_fract_params(void)
{
	static t_fractal 	fract_params[8] = {
		{"mandelbrot", &f_mandelbrot, 1},
		{"celtic_mandelbrot", &f_celtic_mandelbrot, 1},
		{"julia", &f_julia, 1},
		{"burningship", &f_burningship, 1},
		{"perpendicular_burningship", &f_perpendicular_burning_ship, 1},
		{"mandelbar", &f_mandelbar, 1},
		{"celtic_mandelbar", &f_celtic_mandelbar, 1},
		{NULL, NULL, 0}
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

int						main(int argc, char **argv)
{
	t_mlx				mlx;
	char				*t;
	
	t = ft_strdup("asd");
	if (argc != 2 || !(mlx.fractal = is_fractal(argv[1])))
		return(usage_out());
	fractal_init(&mlx);
	if (!(mlx_window_img_init(&mlx)))
		return(pr_out("Error : could not initialize mlx\n"));
	draw(&mlx);
	mlx_hook(mlx.win_ptr, 2, 0, handle_key, &mlx);
	mlx_hook(mlx.win_ptr, 4, 0, zoom_change, &mlx);
	if (!(ft_strcmp(mlx.fractal->name, "julia")))
		mlx_hook(mlx.win_ptr, 6, 0, julia_mouse_move, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
