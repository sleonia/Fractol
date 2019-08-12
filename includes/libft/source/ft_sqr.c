/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:03:27 by sleonia           #+#    #+#             */
/*   Updated: 2019/04/21 17:03:31 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqr(int nbr, int power)
{
	int previous;
	int save;

	save = nbr;
	while (power > 1)
	{
		previous = nbr;
		nbr *= save;
		if (previous > nbr)
			return (save < 0 ? 0 : -1);
		power--;
	}
	return (nbr);
}
