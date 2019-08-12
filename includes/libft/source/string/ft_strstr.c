/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:56:16 by sleonia           #+#    #+#             */
/*   Updated: 2019/04/09 21:03:07 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		k;
	char		*str;

	str = (char *)s1;
	i = 0;
	if (!*s2)
		return (str);
	while (str[i])
	{
		k = 0;
		while (s2[k] == str[i + k])
		{
			if (!(s2[k + 1]))
				return (str + i);
			k++;
		}
		i++;
	}
	return (NULL);
}
