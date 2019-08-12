/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:31:36 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/17 05:41:48 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin_free(char *s1, char *s2, int flag1, int flag2)
{
	char		*str;

	if (!s1)
	{
		s1 = ft_strnew(0);
		flag1 = 1;
	}
	if (!s2)
	{
		s2 = ft_strnew(0);
		flag2 = 1;
	}
	str = ft_strjoin(s1, s2);
	if (flag1 == 1)
		ft_strdel(&s1);
	if (flag2 == 1)
		ft_strdel(&s2);
	return (str);
}
