/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 22:02:36 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/11 13:45:28 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*ts1;
	char	*ts2;
	char	*ret;

	i = 0;
	str1 = (char*)s1;
	if (s1 && s2)
	{
		if (!*s2)
			return ((char*)s1);
		while (*str1++)
		{
			ts1 = (char*)s1;
			ts2 = (char*)s2;
			while (*ts1 != *ts2 && *ts1 && i < n)
				ts1++, i++;
			ret = ts1;
			while (*ts1 == *ts2 && *ts1++ && *ts2++ && i++ < n)
				if (!*ts2)
					return (ret);
		}
	}
	return (NULL);
}
