/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:47:24 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/14 15:03:27 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int						pr_out(char *out_str)
{
	ft_putstr(out_str);
	return(1);
}

int						usage_out()
{
	ft_putstr("Usage : ./fractol <fract_name>\n\n");
	ft_putstr("List of available fractal names:\n");
	ft_putstr("<mandelbrot>\n");
	ft_putstr("<julia>\n");
	ft_putstr("<burningship>\n");
	ft_putstr("<mandelbar>\n");
	return(1);
}