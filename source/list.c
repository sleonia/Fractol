/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:55:26 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/24 20:19:02 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					delete_struct(int key, t_fractol *fractol)
{
	if (key == 2)
	{
		free(fractol->mlx);
		fractol->mlx = NULL;
	}
	if (key == 2 || key == 1)
	{
		free(fractol->cmplx);
		fractol->mlx = NULL;
	}
	if (key == 2 || key == 1 || key == 0)
	{
		free(fractol);
		fractol = NULL;
	}
	return (1);
}

t_fractol			*create_struct(void)
{
	t_fractol		*fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		return (NULL);
	if (!(fractol->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
	{
		delete_struct(0, fractol);
		return (NULL);
	}
	if (!(fractol->cmplx = (t_cmplx *)malloc(sizeof(t_cmplx))))
	{
		delete_struct(1, fractol);
		return (NULL);
	}
	fractol->color = WHITE;
	return (fractol);
}
