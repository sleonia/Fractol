/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:39:57 by sleonia           #+#    #+#             */
/*   Updated: 2019/04/09 21:47:08 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*str;
	unsigned char	symb;

	i = 0;
	str = (char *)b;
	symb = (unsigned char)c;
	while (i < len)
	{
		str[i] = symb;
		i++;
	}
	return (b);
}
