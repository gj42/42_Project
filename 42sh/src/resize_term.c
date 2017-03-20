/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:24:21 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 00:24:11 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					get_line_term(void)
{
	struct winsize	w;
	int				y;

	y = 0;
	if ((ioctl(0, TIOCGWINSZ, &w)) == -1)
		ft_exit("ioctl error");
	y = w.ws_row;
	return (y);
}

static int			get_max_len(t_select *ptr)
{
	size_t			size;

	size = 0;
	while (ptr && ptr->begin != 1)
		ptr = ptr->next;
	while (ptr->next->index != 0)
	{
		if (size < ptr->size)
			size = ptr->size;
		ptr = ptr->next;
	}
	return ((int)size + 2);
}

void				count_and_nb(int *count, int *nb, t_select *ptr, int size)
{
	if (*count < *nb)
	{
		display(ptr, size);
		(*count)++;
	}
	else if (*count == *nb)
	{
		display(ptr, size);
		ft_putstr("\n");
		*count = 0;
	}
}

static int			much_to_print(t_select *ptr, int x, int y)
{
	static	int		count = 0;
	static	int		size = 0;
	int				nb;
	t_select		*tmp;

	tmp = ptr;
	get_term_size(&x, &y);
	if (size == 0)
		size = get_max_len(tmp);
	nb = (x / size);
	if (ptr && ptr->next->index != 0)
		count_and_nb(&count, &nb, ptr, size);
	if (ptr->next->index == 0)
	{
		count = 0;
		size = 0;
		ft_putstr("\n\n");
		if ((tputs(tgetstr("sc", NULL), 1, t_puts)) == -1)
			ft_exit("Tputs error");
		prompt();
	}
	return (nb);
}

void				display_select(t_select *sl)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	g_size = much_to_print(sl, x, y);
}
