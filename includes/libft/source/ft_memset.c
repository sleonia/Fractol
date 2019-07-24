/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:39:57 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/20 23:24:35 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	int				*str;
	unsigned char	symb;

	i = 0;
	str = (int *)b;
	symb = (unsigned char)c;
	while (i < len)
	{
		str[i] = symb;
		i++;
	}
	return (b);
}
