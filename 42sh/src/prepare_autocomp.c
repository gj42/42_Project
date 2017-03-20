/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_autocomp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 17:38:34 by bciss             #+#    #+#             */
/*   Updated: 2016/03/27 17:38:35 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int				get_nb_word(char *str)
{
	int		nb;
	int		i;

	i = -1;
	nb = 0;
	while ((str[++i] == ' ' || str[i] == '\t') && str[i])
		;
	if (!str[i])
		return (0);
	else
		nb = 1;
	while (str[++i])
		if (str[i] == ' ' || str[i] == '\t')
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			nb++;
		}
	return (nb);
}

void			get_cursor_word(char *to_edit, int cursor, char *dest)
{
	char		word[0xf000];
	int			i;
	int			j;

	j = 0;
	i = cursor;
	while ((to_edit[i] != '/' || to_edit[i] != ' ') && to_edit[i])
		i--;
	while ((to_edit[++i] != '\n' || to_edit[i] != ' ') && to_edit[i])
		word[j++] = to_edit[i];
	word[j] = '\0';
	ft_strcpy(dest, word);
}

int				binary_launch(int cursor, char *to_edit)
{
	int				i;
	int				nb;

	i = -1;
	if ((nb = ft_strlen(to_edit) - 1) < 1)
		return (-1);
	while (++i < cursor && i < nb)
		if (to_edit[i] == '.' && to_edit[i + 1] == '/')
			return (i);
	return (-1);
}
