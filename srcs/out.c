/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:47:24 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/21 16:08:20 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int						pr_out(char *out_str)
{
	ft_putstr(out_str);
	return (1);
}

int						usage_out(void)
{
	ft_putstr("Usage : ./fractol <fract_name_1> <fract_name_2> ... ");
	ft_putstr("<fract_name_7>\n\n");
	ft_putstr("List of available fractal names:\n");
	ft_putstr("1: < mandelbrot >\n");
	ft_putstr("2: < celtic_mandelbrot >\n");
	ft_putstr("3: < julia >\n");
	ft_putstr("4: < burningship >\n");
	ft_putstr("5: < perpendicular_burningship >\n");
	ft_putstr("6: < mandelbar >\n");
	ft_putstr("7: < celtic_mandelbar >\n");
	return (1);
}
