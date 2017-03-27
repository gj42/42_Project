/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:20:24 by gjensen           #+#    #+#             */
/*   Updated: 2016/12/12 18:08:26 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*initnorme(char *str1, char *ts1, char *ts2, const char *s2)
{
	char	*ret;

	while (*str1)
	{
		ts1 = (char*)str1;
		ts2 = (char*)s2;
		while (*ts1 != *ts2 && *ts1)
			ts1++;
		ret = ts1;
		while (*ts1 == *ts2 && *ts2 && *ts1)
		{
			ts1++;
			ts2++;
		}
		if (!*ts2)
			return (ret);
		str1++;
	}
	return (NULL);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	char	*ts1;
	char	*ts2;
	char	*str1;

	str1 = (char*)s1;
	ts1 = NULL;
	ts2 = NULL;
	if (s1 && s2)
	{
		if (!*s2)
			return ((char*)s1);
		else
			return (initnorme(str1, ts1, ts2, s2));
	}
	return (NULL);
}
