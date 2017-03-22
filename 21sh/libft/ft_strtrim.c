/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 19:18:52 by vdaviot           #+#    #+#             */
/*   Updated: 2016/05/03 18:52:05 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	slen;
	size_t	i;

	ret = NULL;
	if (s)
	{
		slen = ft_strlen(s);
		if ((ret = (char*)ft_memalloc(slen + 1)) == NULL)
			return (NULL);
		while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
			s++;
		if (ft_strlen(s) == 0)
			return (ret);
		i = 0;
		while (s[i])
			i++;
		i--;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		ft_strncpy(ret, s, i + 1);
		return (ret);
	}
	return (ret);
}
