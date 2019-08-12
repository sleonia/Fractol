/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 06:34:17 by sleonia           #+#    #+#             */
/*   Updated: 2019/05/11 22:24:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t len_dst;
	size_t i;

	i = 0;
	len_dst = ft_strlen(dst);
	while (src[i] && i < len)
	{
		dst[len_dst++] = src[i++];
	}
	dst[len_dst] = '\0';
	return (dst);
}
