/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smarstplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 23:50:55 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 05:29:04 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char	*count_words_spe(char *str, char c)
{
	char q;

	while (*str && *str + 1 && *str == '\\')
		str = str + 2;
	if (*str == '\'' || *str == '\"')
	{
		q = *str;
		str++;
		while (*str && *str != q)
		{
			while (*str == '\\')
				str = str + 2;
			str++;
		}
	}
	if (*str && *str != c)
		str++;
	return (str);
}

int			count_word(char *str, char c)
{
	int		i;
	int		ret;

	ret = 0;
	i = 1;
	if (*str)
		ret++;
	while (*str)
	{
		while (*str && *str != c)
			str = count_words_spe(str, c);
		if (*str == c && (*str) + 1 != c && (*str) + 1 != 0)
			ret++;
		while (*str && *str == c)
			str++;
	}
	return (ret);
}

static char	*ft_smartsplit_spe(char *str, char c)
{
	char	q;

	while (*str + 1 && *str == '\\')
		str = str + 2;
	if (*str == '\'' || *str == '\"')
	{
		q = *str;
		str++;
		while (*str && *str != q)
		{
			while (*str == '\\')
				str = str + 2;
			str++;
		}
	}
	if (*str && *str != c)
		str++;
	return (str);
}

char		**ft_smartsplit(char *str, char c)
{
	char	**ret;
	int		words;
	int		i;
	int		o;

	i = 0;
	o = 0;
	words = count_word(str, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (str && *str)
	{
		ret[o] = ft_strdupcign(str, c);
		o++;
		while (*str && *str != c)
			str = ft_smartsplit_spe(str, c);
		while (*str && *str == c)
			str++;
	}
	ret[o] = NULL;
	return (ret);
}
