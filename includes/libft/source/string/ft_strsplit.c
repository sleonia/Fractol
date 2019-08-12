/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 08:05:22 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/20 09:17:59 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbw(const char *str, char c)
{
	int word;

	word = 0;
	if (*str != c && *str)
	{
		str++;
		word++;
	}
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				word++;
		}
		str++;
	}
	return (word);
}

static int		ln(const char *str, char c)
{
	int count;

	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		j;
	int		i;
	char	**sp;

	j = 0;
	i = 0;
	if (!s || (!(sp = (char **)ft_memalloc(sizeof(char *) * (nbw(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(sp[j] = (char *)ft_memalloc(sizeof(char) * (ln(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				sp[j][i++] = (char)*s++;
			sp[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	sp[j] = NULL;
	return (sp);
}
