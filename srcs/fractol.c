/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:03:05 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/03/23 22:08:25 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					main(int argc, char **argv)
{
	argv++;
	if (argc != 2)
		ft_putstr("Usage : ./fractol <filename>\n");
	else
	{
		ft_putstr("Program was started\n");
		//start
	}
	return (0);
} 