/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 01:25:52 by vdaviot           #+#    #+#             */
/*   Updated: 2016/05/12 05:27:53 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlencign(const char *str, char c)
{
	size_t	i;
	char	q;

	i = 0;
	while (str[i] && str[i] != c)
	{
		while (str[i] && str[i] == '\\')
			i = i + 2;
		if (str[i] == '\'' || str[i] == '\"')
		{
			q = str[i];
			i++;
			while (str[i] && str[i] != q)
			{
				while (str[i] == '\\' && str[i + 1])
					i = i + 2;
				i++;
			}
		}
		if (str[i] && str[i] == '\\')
			i = i + 2;
		else if (str[i] && str[i] != c)
			i++;
	}
	return (i);
}
