/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:03:05 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/21 16:38:27 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractal		*get_fract_params(void)
{
	static t_fractal	fract_params[8] = {
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

static t_fractal		*is_fractal(char *str)
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
	usage_out();
	return (NULL);
}

int						mlx_delete_all(t_mlx *fr, int count)
{
	while (count >= 0)
	{
		mlx_delete(&fr[count]);
		count--;
	}
	return (1);
}

static int				get_n_draw_cur_fractal(char **argv, t_mlx *fr, int i)
{
	fr[i].win_ptr = NULL;
	fr[i].image = NULL;
	if (!(fr[i].fractal = is_fractal(argv[i + 1])))
		return (mlx_delete_all(fr, i - 1));
	fractal_init(&fr[i]);
	if (!(mlx_window_img_init(&fr[i])))
	{
		pr_out("Error : could not initialize image and/or window\n");
		mlx_delete_all(fr, i - 1);
	}
	draw(&fr[i]);
	mlx_hook(fr[i].win_ptr, 2, 0, handle_key, &fr[i]);
	mlx_hook(fr[i].win_ptr, 4, 0, zoom_change, &fr[i]);
	if (!(ft_strcmp(fr[i].fractal->name, "julia")))
		mlx_hook(fr[i].win_ptr, 6, 0, julia_mouse_move, &fr[i]);
	return (0);
}

int						main(int argc, char **argv)
{
	void				*mlx_ptr;
	t_mlx				fractals[argc - 1];
	int					i;

	if (argc < 2 || argc > FRACT_COUNT + 1)
		return (usage_out());
	if (!(mlx_ptr = mlx_init()))
		return (pr_out("Error : could not initialize mlx\n"));
	i = -1;
	while (++i < argc - 1)
	{
		fractals[i].mlx_ptr = mlx_ptr;
		get_n_draw_cur_fractal(argv, fractals, i);
	}
	mlx_loop(mlx_ptr);
	return (0);
}
