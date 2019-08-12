/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:53:15 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/11 13:53:33 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*str1;
	char		*str2;

	i = 0;
	if (!dst && !src)
		return (NULL);
	str1 = (char *)dst;
	str2 = (char *)src;
	while (i++ < n)
		str1[i] = str2[i];
	return ((void *)str1);
}
