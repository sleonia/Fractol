/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 06:43:32 by sleonia           #+#    #+#             */
/*   Updated: 2019/04/11 06:43:35 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t k;
	size_t len;

	if (!dst && !src)
		return (0);
	i = 0;
	k = 0;
	len = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	if (size > 0)
	{
		while (src[k] && i < size - 1)
		{
			dst[i++] = src[k++];
		}
	}
	if (k > 0)
	{
		dst[i] = '\0';
		return (len + i - k);
	}
	return (len + i);
}
