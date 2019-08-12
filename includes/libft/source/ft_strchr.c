/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:02:36 by sleonia           #+#    #+#             */
/*   Updated: 2019/05/12 18:04:38 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char symb;

	symb = (unsigned char)c;
	while (*s != symb)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *)s);
}
