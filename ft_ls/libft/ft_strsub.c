/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 18:02:35 by gjensen           #+#    #+#             */
/*   Updated: 2015/01/15 22:40:27 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	slen;
	size_t	i;

	ret = NULL;
	if (s)
	{
		slen = ft_strlen(s);
		if (!slen || start > slen || len > slen)
			return (NULL);
		if ((ret = (char*)ft_memalloc(len + 1)) == NULL)
			return (NULL);
		i = 0;
		while (s[i] && i < len)
		{
			ret[i] = s[start];
			i++;
			start++;
		}
		ret[i] = 0;
		return (ret);
	}
	return (NULL);
}
