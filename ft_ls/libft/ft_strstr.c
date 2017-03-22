/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:20:24 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/17 15:26:24 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*ts1;
	char	*ts2;
	char	*ret;
	char	*str1;

	str1 = (char*)s1;
	if (s1 && s2)
	{
		if (!*s2)
			return ((char*)s1);
		while (*str1)
		{
			ts1 = (char*)str1;
			ts2 = (char*)s2;
			while (*ts1 != *ts2 && *ts1)
				ts1++;
			ret = ts1;
			while (*ts1 == *ts2 && *ts2 && *ts1)
				ts1++, ts2++;
			if (!*ts2)
				return (ret);
			str1++;
		}
	}
	return (NULL);
}
