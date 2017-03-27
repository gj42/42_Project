/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:37:26 by gjensen           #+#    #+#             */
/*   Updated: 2016/12/12 15:59:45 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_mdata	*find_mdataptr(void *ptr, t_page *page)
{
	t_mdata	*mdata;

	if (page)
	{
		mdata = page->start;
		while (mdata)
		{
			if (mdata == (void *)ptr - sizeof(t_mdata))
				return (mdata);
			mdata = mdata->next;
		}
	}
	return (NULL);
}

t_page	*find_pageptr(void *ptr)
{
	t_page	*tmp;

	if (!g_firstpage)
		return (NULL);
	if ((tmp = g_firstpage))
	{
		while (tmp)
		{
			if (ptr >= (void *)tmp->start && ptr < (void *)tmp->start +
					tmp->size)
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (NULL);
}

int		free_page(t_page *page)
{
	t_page *tmp;

	if ((tmp = g_firstpage))
	{
		if (page == g_firstpage)
		{
			g_firstpage = page->next;
			return (munmap((void *)page, page->size + sizeof(t_page)));
		}
		else
		{
			while (tmp->next)
			{
				if (page == tmp->next)
				{
					tmp->next = page->next;
					return (munmap((void *)page, page->size + sizeof(t_page)));
				}
				tmp = tmp->next;
			}
		}
	}
	return (1);
}

void	free(void *ptr)
{
	t_page	*page;
	t_mdata	*mdata;

	if (!ptr)
		return ;
	if ((page = find_pageptr(ptr)) == NULL)
		return ;
	if ((mdata = find_mdataptr(ptr, page)) == NULL)
		return ;
	if (page->type == LARGE)
	{
		free_page(page);
		return ;
	}
	mdata->free = 1;
	ptr = NULL;
}
