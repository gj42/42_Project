/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:15:22 by bciss             #+#    #+#             */
/*   Updated: 2016/05/18 15:40:33 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int	count_c(char *str, char c)
{
	int		nb;
	int		i;

	i = -1;
	nb = 0;
	while (str[++i])
		if (str[i] == c)
			nb++;
	return (nb);
}

char		**ft_command_split_last_c(char *to_complete, char c)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (to_complete[ft_strlen(to_complete) - 1] == '/')
		return (NULL);
	if (count_c(to_complete, c) == 0)
		return (ft_strsplit(to_complete, ' '));
	while (to_complete[i] != ' ')
		i++;
	to_complete[i] = '\n';
	i = ft_strlen(to_complete);
	while (to_complete[i] != c)
		i--;
	to_complete[i] = '\n';
	return (ft_strsplit(to_complete, '\n'));
}

char		**get_autocomp_path(char *to_complete)
{
	char	**tb;

	if (!(tb = ft_command_split_last_c(to_complete, '/')))
		return (NULL);
	if (!(tb[2]))
	{
		tb[2] = ft_strdup(tb[1]);
		tb[1] = ft_strdup(".");
	}
	return (tb);
}

char		*get_missing_chars(char *base, int cursor, char *complete)
{
	int		i;
	int		j;
	char	buf[0xf000];
	char	buffer[0xf000];

	get_cursor_word(base, cursor, buf);
	i = -1;
	j = 0;
	while (complete[++i])
	{
		while ((size_t)i < ft_strlen(buf))
			i++;
		buffer[j++] = complete[i];
	}
	buffer[j] = '\0';
	return (ft_strdup(buffer));
}
