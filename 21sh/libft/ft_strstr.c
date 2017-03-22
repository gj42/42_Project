/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:59:03 by vdaviot           #+#    #+#             */
/*   Updated: 2015/01/11 00:49:14 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	k;
	int	j;
	int	l;

	i = -1;
	j = ft_strlen(s2);
	if (s2 == NULL || s2[0] == '\0')
		return ((char *)s1);
	l = 0;
	while (s1[++i] != '\0')
		if (s1[i] == s2[0])
		{
			l = i;
			k = 0;
			while (s1[l] == s2[k])
			{
				if (k == (j - 1))
					return ((char *)s1 + i);
				l++;
				k++;
			}
		}
	return (NULL);
}
