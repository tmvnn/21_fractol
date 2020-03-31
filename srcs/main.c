/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:03:05 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/03/31 21:20:52 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				*pr_error(char *err_msg)
{
	perror(err_msg);
	exit(1);
}

int					pr_out(char *out_str)
{
	ft_putstr(out_str);
	return(1);
}

int					main(int argc, char **argv)
{
	errno = 0;
	argv++;
	if (argc != 2)
		return(pr_out("Usage : ./fractol <fract_name>\n"));
	//render("Program was started\n");
	return (0);
}