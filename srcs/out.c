/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:47:24 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/04/07 19:48:44 by timuryakubo      ###   ########.fr       */
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