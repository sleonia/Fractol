/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 06:23:27 by sleonia           #+#    #+#             */
/*   Updated: 2019/04/11 06:23:29 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(dst);
	while (src[i])
	{
		dst[len++] = src[i++];
	}
	dst[len] = '\0';
	return (dst);
}
