/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:58:38 by sleonia           #+#    #+#             */
/*   Updated: 2019/04/11 10:58:40 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_counter_i(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		if (!(s[i + 1]))
			return (-1);
		i++;
	}
	return (i);
}

char				*ft_strtrim(char const *s)
{
	char		*str;
	int			i;
	int			j;
	int			k;

	if (!s)
		return ((char *)s);
	i = ft_counter_i(s);
	if (i < 0)
		return (ft_strnew(0));
	j = 0;
	k = ft_strlen(s) - 1;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k--;
	str = (char *)malloc(sizeof(char) * (k - i + 2));
	if (!str)
		return (NULL);
	while (i <= k)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
