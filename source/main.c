/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:18:07 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/03 11:15:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int			error_prosessing(int key)
{
	if (key == 0)
		ft_putstr("\033[31merror\033[0m\n");
	if (key == 1)
		ft_putstr("\n\033[31mYou entered the wrong argument!\033[0m\n\
\033[32mYou can only enter these arguments:\n\
\033[33m0 - Mandelbrot\n\
\033[34m1 - Julia\n");
	return (1);
}

static	int			arg_prosessing(char *arg)
{
	if ((ft_getnbr(arg) ^ MANDELBROT) == 0)
		return (0);
	if ((ft_getnbr(arg) ^ JULIA) == 0)
		return (1);
	return (-1);
}

int					main(int ac, char **av)
{
	int				key;
	t_fractol		*fractol;

	if (ac == 2)
	{
		if (!(fractol = create_struct()))
			return (error_prosessing(0));
		if ((fractol->arg = arg_prosessing(av[1])) < 0)
			return (error_prosessing(1));
		if (create_window(fractol) == 1)
			return (error_prosessing(0));
	}
	else
		return (error_prosessing(1));
	return (0);
}
