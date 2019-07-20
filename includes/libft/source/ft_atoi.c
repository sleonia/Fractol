/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:18:35 by sleonia           #+#    #+#             */
/*   Updated: 2019/04/09 14:27:47 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	previous;
	long int	nb;
	int			key;

	nb = 0;
	key = 1;
	while (*str == '\n' || *str == '\t' || *str == '\r'
		|| *str == ' ' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			key = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		previous = nb;
		nb = nb * 10 + (*str++ - '0');
		if (previous > nb)
			return (key == -1 ? 0 : -1);
	}
	return (key * (int)nb);
}
