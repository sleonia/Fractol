/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findsymb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 22:12:33 by sleonia           #+#    #+#             */
/*   Updated: 2019/05/11 22:17:52 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_findsymb(const char *s, int c)
{
	unsigned char symb;

	if (!s)
		return (NULL);
	symb = (unsigned char)c;
	while (*s != symb)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *)s);
}
