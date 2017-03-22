/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 19:18:52 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/17 16:28:47 by gjensen          ###   ########.fr       */
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
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		if (ft_strlen(s) == 0)
			return (ret = ft_strnew(0));
		i = 0;
		while (s[i])
			i++;
		i--;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		ft_strncpy(ret, s, i + 1);
		return (ret);
	}
	return (NULL);
}
