/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:10:04 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 05:03:52 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "libft.h"

int		w_isspace(char *str, int i)
{
	while ((str[i] == ' ') || (str[i] == '\t'))
		i++;
	return (i);
}

char	*ft_strspetrim(char *s, int i, int j)
{
	char	x;
	char	dup[0xffff];
	char	*tmp;

	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		i = w_isspace(s, i);
		if (i != 0 && (s[i - 1] == ' ' || s[i - 1] == '\t'))
			dup[j++] = ' ';
		if (s[i] == '\'' || s[i] == '\"')
		{
			x = s[i];
			dup[j++] = s[i++];
			while (s[i] != x && s[i] != '\0')
				dup[j++] = s[i++];
		}
		while (s[i] != '\t' && s[i] != ' ' && s[i] != '\"' && s[i] != '\''
				&& s[i] != '\0')
			dup[j++] = s[i++];
	}
	dup[j] = '\0';
	tmp = ft_strtrim(dup);
	return (tmp);
}
