/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_page.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:41:17 by gjensen           #+#    #+#             */
/*   Updated: 2016/12/12 16:13:41 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	get_max_size(char type, size_t size)
{
	if (type == TINY)
		return (TINY_SIZE_MAX);
	else if (type == SMALL)
		return (SMALL_SIZE_MAX);
	else
		return (size);
	print_error("Max size error");
	return (0);
}

void	*find_page(size_t size)
{
	t_page	*page;
	char	type;

	page = g_firstpage;
	type = get_sizetype(size);
	while (page)
	{
		if (page->type == type && !page->full)
		{
			if ((page->size + size + sizeof(t_mdata)) >
					get_max_size(type, size))
			{
				page->full = 1;
				return (NULL);
			}
			else
			{
				page->size += size + sizeof(t_mdata);
				return (page);
			}
		}
		page = page->next;
	}
	return (NULL);
}

void	set_metadata(size_t size, t_mdata *mdata, void *next)
{
	mdata->next = next;
	mdata->size = size;
	mdata->free = 0;
}

t_page	*set_page(t_page *page, char type)
{
	page->size = 0;
	page->full = 0;
	page->type = type;
	page->next = NULL;
	page->start = page + 1;
	return (page);
}

void	*page_push(t_page *first, size_t size, char type)
{
	t_page	*tmp;

	if (!first)
	{
		if ((first = (void *)mmap(0, get_max_size(type, size) +
				sizeof(t_page), PROT_READ | PROT_WRITE, MAP_ANON
				| MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			print_error("Mapping failed");
		first = set_page(first, type);
	}
	else
	{
		tmp = first;
		while (tmp->next)
			tmp = tmp->next;
		if ((tmp->next = (void *)mmap(0, get_max_size(type, size) +
				sizeof(t_page), PROT_READ | PROT_WRITE, MAP_ANON
				| MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			print_error("Mapping failed");
		tmp->next = set_page(tmp->next, type);
		tmp = tmp->next;
		return (tmp);
	}
	return (first);
}
