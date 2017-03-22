/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 01:43:59 by vdaviot           #+#    #+#             */
/*   Updated: 2016/05/12 05:28:06 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_find_quotes(const char *src, char *str, int *i)
{
	char q;

	if (src[*i] == '\'' || src[*i] == '\"')
	{
		q = src[*i];
		str[*i] = src[*i];
		(*i)++;
		while (src[*i] && src[*i] != q)
		{
			while (src[*i] == '\\' && src[*i + 1])
			{
				str[*i] = src[*i];
				(*i)++;
				str[*i] = src[*i];
				(*i)++;
			}
			str[*i] = src[*i];
			(*i)++;
		}
	}
	return (str);
}

char		*ft_strdupcign(const char *src, char c)
{
	int		i;
	char	*str;

	i = 0;
	if ((str = (char*)malloc(sizeof(char) *
					(ft_strlencign(src, c) + 1))) == NULL)
		return (NULL);
	while (src[i] && src[i] != c)
	{
		while (src[i + 1] && src[i] == '\\')
		{
			str[i] = src[i];
			i++;
			str[i] = src[i];
			i++;
		}
		str = ft_find_quotes(src, str, &i);
		if (src[i] && src[i] != c)
		{
			str[i] = src[i];
			i++;
		}
	}
	str[i] = 0;
	return (str);
}
