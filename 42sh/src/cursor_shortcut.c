/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_shortcut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 17:38:17 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 06:01:28 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					size_until_next_word(char *sentence, int cursor)
{
	int		i;

	i = cursor;
	while (sentence[i] != ' ' && sentence[i] != '\t' && sentence[i] != '\n' &&
			sentence[i] != '\0')
		i++;
	while (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t')
		i++;
	if (sentence[i] == '\0')
		i--;
	return (i - cursor + 1);
}

int					size_until_prev_word(char *str, int cursor)
{
	int		i;
	int		j;

	i = 0;
	while (i < cursor)
	{
		if ((i == 0 && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')) ||
				((str[i] != ' ' && str[i] != '\n' && str[i] != '\t') &&
				(str[i - 1] == ' ' || str[i - 1] == '\n' ||
				str[i - 1] == '\t')))
			j = i;
		i++;
	}
	return (j);
}
