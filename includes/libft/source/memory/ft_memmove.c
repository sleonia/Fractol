/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:17:19 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/11 13:52:11 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	char		*s;
	size_t		i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (s > d)
	{
		while (i++ < len)
			d[i] = s[i];
	}
	else if (s < d)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	return (dst);
}
