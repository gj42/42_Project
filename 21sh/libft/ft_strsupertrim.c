/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsupertrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 17:31:19 by vdaviot           #+#    #+#             */
/*   Updated: 2016/01/29 21:48:42 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsupertrim(char *str)
{
	int		i;
	int		j;
	char	dup[2048];

	i = 0;
	j = 0;
	ft_bzero(dup, 2048);
	while (str[i] != '\0')
	{
		while ((str[i] == ' ') || (str[i] == '\t'))
			i++;
		if (i != 0 && (str[i - 1] == ' ' || str[i - 1] == '\t')
				&& str[i] != '\n')
			dup[j++] = ' ';
		while (str[i] != '\t' && str[i] != ' ' && str[i] != '\0')
			dup[j++] = str[i++];
	}
	dup[i] = '\0';
	ft_strcpy(str, dup);
	return (ft_strtrim(str));
}
