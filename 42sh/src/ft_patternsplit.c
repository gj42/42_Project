/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patternsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 21:13:23 by bciss             #+#    #+#             */
/*   Updated: 2016/05/19 22:15:32 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					verif_pattern(char *pattern, char *buf, int start, int end)
{
	int				i;

	i = start - 1;
	while (buf[++i] && i <= end)
	{
		if (buf[i] == pattern[0] && buf[i + 1] == pattern[1])
			if (buf[i - 11] && buf[i - 11] == '[')
			{
				while (buf[i++] != '[' && buf[i])
					;
				return (i - 1);
			}
	}
	return (0);
}

char				*get_str_index(char *buf, int start, int end)
{
	char			tmp[0xf000];
	int				i;
	int				k;

	i = start - 1;
	k = -1;
	while (i < 0xf000 - 1 && buf[++i] && i <= end)
		tmp[++k] = buf[i];
	tmp[++k] = '\0';
	return (ft_strdup(tmp));
}

void				ft_strpatternsplit(char **array, char *buf, char *pattern)
{
	int				i;
	int				k;
	int				s;
	int				m;
	char			*tmp;

	i = -1;
	k = 0;
	s = 0;
	m = 0;
	array[count_lines_file(g_history_file)] = NULL;
	while (buf[++i] && s <= count_lines_file(g_history_file))
	{
		if (buf[i] == pattern[1] && buf[i - 1] == pattern[0])
		{
			if ((m = verif_pattern(pattern, buf, k, i)) > 0)
			{
				tmp = get_str_index(buf, k, m - 1);
				array[s++] = ft_strdupc(tmp, '\n');
				ft_strdel(&tmp);
				k = m;
			}
		}
	}
	array[s] = NULL;
}
