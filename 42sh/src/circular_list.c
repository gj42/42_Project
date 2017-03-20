/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 23:54:13 by bciss             #+#    #+#             */
/*   Updated: 2016/04/21 01:46:09 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		ft_add_after_root_clist(t_select **circ, char *str)
{
	t_select *tmp;

	if (!*circ)
		*circ = ft_select_init_clist(str);
	if (!(tmp = (t_select*)malloc(sizeof(t_select))))
		return ;
	ft_strcpy(tmp->word, str);
	tmp->size = ft_strlen(str);
	tmp->atm = 0;
	tmp->choosed = 0;
	tmp->prev = *circ;
	tmp->next = (*circ)->next;
	(*circ)->next->prev = tmp;
	(*circ)->next = tmp;
	tmp->index = (*circ)->index + 1;
}

t_select	*ft_select_init_clist(char *str)
{
	t_select	*list;

	if (!(list = (t_select*)malloc(sizeof(t_select))))
		return (NULL);
	list->atm = 1;
	list->begin = 1;
	list->index = 0;
	ft_strcpy(list->word, str);
	list->size = ft_strlen(str);
	list->next = list;
	list->prev = list;
	return (list);
}

void		ft_add_before_root_clist(t_select **circ, char *str)
{
	t_select *tmp;

	if (*circ == NULL)
	{
		*circ = ft_select_init_clist(str);
		return ;
	}
	if (!(tmp = (t_select*)malloc(sizeof(t_select))))
		exit(-1);
	ft_strcpy(tmp->word, str);
	tmp->size = ft_strlen(str);
	tmp->atm = 0;
	tmp->choosed = 0;
	tmp->prev = (*circ)->prev;
	tmp->next = *circ;
	tmp->index = (*circ)->index + 1;
	(*circ)->prev->next = tmp;
	(*circ)->prev = tmp;
	return ;
}
