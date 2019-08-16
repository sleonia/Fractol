/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:18:07 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/16 20:29:07 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					error_prosessing(int key)
{
	if (key == 0)
		ft_putstr("\033[31merror\033[0m\n");
	if (key == 1)
		ft_putstr("\n\033[31mYou entered the wrong argument!\033[0m\n\
\033[32mYou can only enter these arguments:\n\
\033[33m0 - Mandelbrot\n\
\033[34m1 - Julia\n\
\033[35m2 - Burning Ship\n\
\033[36m3 - Mandelbar\n\
\033[33m4 - Spider\n\
\033[34m5 - Celtic Mandelbrot\n\
\033[36m6 - Butterfly\n");
	return (1);
}

static	int			arg_prosessing(char *arg)
{
	if (ft_strcmp(arg, "0") == 0)
		return (0);
	if (ft_strcmp(arg, "1") == 0)
		return (1);
	if (ft_strcmp(arg, "2") == 0)
		return (2);
	if (ft_strcmp(arg, "3") == 0)
		return (3);
	if (ft_strcmp(arg, "4") == 0)
		return (4);
	if (ft_strcmp(arg, "5") == 0)
		return (5);
	if (ft_strcmp(arg, "6") == 0)
		return (6);
	return (-1);
}

int					main(int ac, char **av)
{
	int				key;
	t_fractol		*f;

	if (ac == 2)
	{
		if (!(f = create_struct()))
			return (error_prosessing(0));
		if ((f->fractol = arg_prosessing(av[1])) < 0)
			return (error_prosessing(1));
		if (create_window(f) == 1)
			return (error_prosessing(0));
	}
	else
		return (error_prosessing(1));
	return (0);
}
