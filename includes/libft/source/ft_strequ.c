/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:23:16 by sleonia           #+#    #+#             */
/*   Updated: 2019/04/11 10:23:24 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t		i;
	char		*str1;
	char		*str2;

	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	else
	{
		i = 0;
		str1 = (char *)s1;
		str2 = (char *)s2;
		while (str1[i] == str2[i])
		{
			if (!(str1[i + 1]) && !(str2[i + 1]))
				return (1);
			i++;
		}
	}
	return (0);
}
