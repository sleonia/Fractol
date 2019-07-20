/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:20:13 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/20 13:34:35 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				put_pixel(t_fractol *fractol, int x, int y, int color)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		ft_memcpy(&(fractol)->mlx->data[(x * 4) + (y * (fractol)->mlx->size_line)], \
												&color, (size_t)(sizeof(int)));
}
