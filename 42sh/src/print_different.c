/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_different.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 15:41:10 by bciss             #+#    #+#             */
/*   Updated: 2016/05/04 20:17:14 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		ft_putstr_bold(char *str)
{
	tputs(tgetstr("md", NULL), 1, t_puts);
	ft_putstr(str);
	tputs(tgetstr("me", NULL), 1, t_puts);
}

void		ft_putstr_bold_start(char *str, int start, int end)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (i == start)
			tputs(tgetstr("md", NULL), 1, t_puts);
		ft_putchar(str[i]);
		if (i == end)
			tputs(tgetstr("me", NULL), 1, t_puts);
	}
}

void		ft_putstr_bold_cr(char *str, char *color)
{
	tputs(tgetstr("md", NULL), 1, t_puts);
	ft_putstr_cr(color, str);
	tputs(tgetstr("me", NULL), 1, t_puts);
}
