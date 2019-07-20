/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__low_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:10:16 by sleonia           #+#    #+#             */
/*   Updated: 2019/04/25 21:10:19 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlow(char *s)
{
	char		*str;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i])
	{
		while (s[i] && s[i] >= 65 && s[i] <= 90)
		{
			str[i] = s[i] + 32;
			i++;
			if (!s[i])
			{
				str[i] = '\0';
				return (str);
			}
		}
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
