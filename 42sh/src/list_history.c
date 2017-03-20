/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:22:41 by bciss             #+#    #+#             */
/*   Updated: 2016/05/19 22:16:57 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_hist				*ft_histo_init_clist(char *str)
{
	t_hist			*histo;

	if (!(histo = (t_hist*)malloc(sizeof(t_hist))))
		return (histo);
	ft_strlcat(histo->str, str + 13, 0xf000);
	set_time(histo);
	histo->index = 0;
	histo->next = NULL;
	return (histo);
}

void				ft_histo_add_clist(t_hist **histo, char *str)
{
	t_hist			*ptr;
	t_hist			*end;
	static	int		index = 1;

	if (!*histo)
	{
		*histo = ft_histo_init_clist(str);
		return ;
	}
	if (!(ptr = (t_hist*)malloc(sizeof(t_hist))))
		return ;
	end = *histo;
	while (end->next)
		end = end->next;
	ptr->index = index++;
	ptr->next = NULL;
	ft_bzero(ptr->str, 0xf000);
	(str[0] == '[') ? ft_strlcat(ptr->str, str + 13, 0xf000) :
		ft_strlcat(ptr->str, str, 0xf000);
	set_time(ptr);
	end->next = ptr;
}

char				*ft_get_line_history(char *to_edit, int line)
{
	t_hist			*tmp;
	int				nb;

	nb = 0;
	tmp = g_history;
	while (tmp)
	{
		if (tmp->index == line)
			return (ft_strcpy(to_edit, tmp->str));
		tmp = tmp->next;
	}
	return (to_edit);
}

void				ft_init_history(void)
{
	static	t_hist	*history = NULL;
	char			**tb;
	int				i;
	int				size;

	size = count_lines_file(g_history_file);
	i = -1;
	if (!(tb = (char **)malloc(sizeof(char*) * (size + 1))))
		return ;
	get_history_content(tb, g_history_file);
	while (tb[++i])
	{
		ft_histo_add_clist(&history, tb[i]);
		if (i == 0)
			g_history = history;
	}
	ft_arrfree(&tb);
}

void				ft_add_history(char *str)
{
	char				*tmp;
	t_hist				*ptr;

	tmp = ft_itoa(get_timestamp());
	if (g_history == NULL)
	{
		ft_add_history_file(tmp, str);
		ft_init_history();
		return ;
	}
	ptr = g_history;
	ft_add_history_file(tmp, str);
	ft_histo_add_clist(&ptr, str);
	ft_strdel(&tmp);
}
