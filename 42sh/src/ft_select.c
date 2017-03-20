/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 23:52:23 by bciss             #+#    #+#             */
/*   Updated: 2016/05/16 19:12:13 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char				*ft_select(char **av)
{
	int				i;
	char			*selected;
	char			*tmp;
	struct termios	term_basic;
	t_select		*list;

	list = NULL;
	i = -1;
	term_basic = set_term_canon();
	selected = NULL;
	while (av[++i])
		ft_add_after_root_clist(&list, av[i]);
	selected = do_select(list);
	tmp = ft_strdup(selected);
	free_the_shit(&list);
	ft_arrfree(&av);
	return (unset_term_canon(term_basic, tmp));
}

char				*get_choosen_word(t_select *list)
{
	while (list)
	{
		if (list->choosed == 1)
			return (list->word);
		list = list->next;
	}
	return (NULL);
}

void				do_refresh(t_select *list)
{
	if ((tputs(tgetstr("rc", NULL), 1, t_puts)) == -1)
		ft_exit("Tputs error");
	if ((tputs(tgetstr("cl", NULL), 1, t_puts)) == -1)
		ft_exit("Tputs error");
	while (list)
	{
		display_select(list);
		list = list->next;
		if (list->index == 0)
			break ;
	}
}

void				display(t_select *list, size_t size)
{
	if (list->choosed == 1)
		if ((tputs(tgetstr("mr", NULL), 1, t_puts)) == -1)
			ft_exit("Tputs error");
	if (list->atm == 1)
		if ((tputs(tgetstr("us", NULL), 1, t_puts)) == -1)
			ft_exit("Tputs error");
	ft_putstr(list->word);
	if ((tputs(tgetstr("ue", NULL), 1, t_puts)) == -1)
		ft_exit("Tputs error");
	if ((tputs(tgetstr("me", NULL), 1, t_puts)) == -1)
		ft_exit("Tputs error");
	ft_precision(list->word, size - 4);
}

void				key_wait(t_select *list)
{
	int			key;

	key = 0;
	read(0, &key, sizeof(int));
	if (key == LEFT)
		c_left(list);
	else if (key == RIGHT)
		c_right(list);
	else if (key == UP)
		c_up(list);
	else if (key == DOWN)
		c_down(list);
	else if (key == SPC || key == TAB || key == RETURN)
		choose(list);
	else if (key == ESC)
		ft_exit("Closing the program, settings reverted.\n");
	else
		;
}
