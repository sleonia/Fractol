/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:18:07 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/20 12:34:13 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int			error_prosessing(void)
{
	ft_putstr("\033[31merror\033[0m\n");
	return (1);
}

int					main(int ac, char **av)
{
	t_fractol		*fractol;

	if (ac == 2)
	{
		if (!(fractol = create_struct()))
			return (error_prosessing());
		window(fractol);
	}
	else
		return (error_prosessing());
	return (0);
}
