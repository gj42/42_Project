/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:16:45 by bciss             #+#    #+#             */
/*   Updated: 2016/05/13 18:39:25 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int				set_next_prompt(char *prompt, int cursor, char *to_edit)
{
	int		i;

	i = -1;
	cursor = 0;
	(void)prompt;
	while (++i < 2)
		if ((tputs(tgetstr("cr", NULL), 1, t_puts)) == -1)
			ft_exit("Tputs error");
	ft_refresh(to_edit, cursor);
	tputs(tgetstr("ve", NULL), 1, t_puts);
	return (cursor);
}

int				t_puts(int c)
{
	ft_putchar(c);
	return (0);
}

char			*nm_trim(char *to_edit)
{
	char		edited[0xf000];
	int			i;
	int			j;

	i = -1;
	j = 0;
	while (to_edit[++i])
		edited[j++] = to_edit[i];
	while (edited[j--] == ' ' || edited[j--] == '\t')
		edited[j] = '\0';
	return (ft_strcpy(to_edit, edited));
}

char			*ac_missing_chars(char *start, int cursor, char *complete)
{
	int			i;

	if (!start || !complete || cursor <= 0)
		return (NULL);
	i = 0;
	while (start[i++] && complete[i])
		if (start[i] != complete[i])
			break ;
	if (i != cursor)
		return (NULL);
	return (complete + i);
}
