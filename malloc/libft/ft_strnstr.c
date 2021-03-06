/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 22:02:36 by gjensen           #+#    #+#             */
/*   Updated: 2016/12/12 18:27:08 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	multiexpression_statement(char **ts1, size_t *i)
{
	(*ts1)++;
	(*i)++;
}

static char	*ft_strnstrcut(const char *s1, const char *s2, size_t n, size_t i)
{
	char	*ts1;
	char	*ts2;
	char	*ret;
	char	*str1;

	str1 = (char*)s1;
	while (*str1++)
	{
		ts1 = str1;
		ts2 = (char*)s2;
		while (*ts1 != *ts2 && *ts1 && i < n)
			multiexpression_statement(&ts1, &i);
		ret = ts1;
		while (*ts1 == *ts2 && *ts1++ && *ts2++ && i++ < n)
		{
			if (*ts1 != *ts2 && *ts2)
			{
				str1 = (char*)s1 + 1;
				n--;
			}
			else if (!*ts2 && i < n)
				return (ret);
		}
	}
	return (NULL);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*ret;

	ret = NULL;
	if (s1 && s2)
	{
		if (!*s2)
			return ((char*)s1);
		ret = ft_strnstrcut(s1, s2, n, 0);
	}
	return (ret);
}
