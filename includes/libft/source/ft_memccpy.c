/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:42:28 by sleonia           #+#    #+#             */
/*   Updated: 2019/04/10 20:58:29 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	symb;
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	symb = (unsigned char)c;
	while (n > 0)
	{
		if (s2[i] == symb)
		{
			s1[i] = s2[i];
			return (dst + i + 1);
		}
		else
			s1[i] = s2[i];
		i++;
		n--;
	}
	return (0);
}
