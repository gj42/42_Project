/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 18:33:13 by gjensen           #+#    #+#             */
/*   Updated: 2016/04/19 19:20:48 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

struct termios	set_term_canon(void)
{
	char			*term_name;
	struct termios	term;
	struct termios	term_basic;

	if ((tcgetattr(0, &term)) == -1)
		return (term);
	if (!(term_name = getenv("TERM")))
		return (term);
	if (!(tgetent(NULL, term_name)))
		return (term);
	term_basic = term;
	term.c_lflag &= (unsigned long)~(ICANON);
	term.c_lflag &= (unsigned long)~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if ((tcsetattr(0, TCSADRAIN, &term)) == -1)
		return (term);
	return (term_basic);
}

char			*unset_term_canon(struct termios term_basic,
				char *selected, char **av)
{
	if ((tcgetattr(0, &term_basic)) == -1)
		return (NULL);
	if ((tcsetattr(0, TCSADRAIN, &term_basic)) == -1)
		return (NULL);
	tputs(tgetstr("ve", NULL), 1, t_puts);
	(void)av;
	return (selected);
}
