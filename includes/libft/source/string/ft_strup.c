/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:06:29 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/09 10:33:42 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strup(char *s)
{
	char		*str;
	size_t		i;

	if (!s)
		return (NULL);
	i = -1;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[++i])
	{
		while (s[i] && s[i] >= 97 && s[i] <= 122)
		{
			str[i] = s[i] - 32;
			++i;
			if (!s[i])
			{
				str[i] = '\0';
				return (str);
			}
		}
		str[i] = s[i];
	}
	str[i] = '\0';
	return (str);
}
