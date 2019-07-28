/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:18:07 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/28 01:25:46 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int			error_prosessing(void)
{
	ft_putstr("\033[31merror\033[0m\n");
	return (1);
}

static	int			arg_prosessing(char *arg)
{
	if (ft_strcmp(arg, MANDELBROT) == 0)
		return (1);
	if (ft_strcmp(arg, JULIA) == 0)
		return (2);
	return (-1);
}

int					main(int ac, char **av)
{
	int				key;
	t_fractol		*fractol;

	if (ac == 2)
	{
		if (!(fractol = create_struct()))
			return (error_prosessing());
		if ((fractol->arg = arg_prosessing(av[1])) < 0)
			return (error_prosessing());
		if (create_window(fractol) == 1)
			return (error_prosessing());
	}
	else
		return (error_prosessing());
	return (0);
}
