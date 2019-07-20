/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:59:56 by sleonia           #+#    #+#             */
/*   Updated: 2019/04/10 21:02:32 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	symb;
	char	*str;
	size_t	i;

	str = (char *)s;
	symb = (char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == symb)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
