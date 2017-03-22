/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:31:22 by vdaviot           #+#    #+#             */
/*   Updated: 2016/03/29 22:21:31 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	k;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = ft_memalloc(i);
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i] != '\0')
		str[k++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[k++] = s2[i++];
	str[k] = '\0';
	return (str);
}
