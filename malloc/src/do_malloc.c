/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:36:59 by gjensen           #+#    #+#             */
/*   Updated: 2016/12/12 16:10:23 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char	get_sizetype(size_t size)
{
	if (size < TINY_SIZE)
		return (TINY);
	else if (size >= TINY_SIZE && size < SMALL_SIZE)
		return (SMALL);
	else if (size >= SMALL_SIZE)
		return (LARGE);
	print_error("Wrong size for allocation");
	return (0);
}

void	*malloc_large(size_t size)
{
	t_page *page;

	page = page_push(g_firstpage, size, get_sizetype(size));
	if (!g_firstpage)
		g_firstpage = page;
	page->size = size + sizeof(t_mdata);
	return (init_block(page->start, size));
}

void	*init_block(void *ptr, size_t size)
{
	t_mdata	*mdata;
	char	*next;

	mdata = ptr;
	while (mdata->next)
	{
		if (mdata->free && mdata->size >= size)
		{
			set_metadata(size, mdata, mdata->next);
			return (mdata + 1);
		}
		mdata = mdata->next;
	}
	if (mdata->size)
	{
		next = (char *)(mdata) + mdata->size + sizeof(t_mdata);
		mdata->next = (void *)next;
		mdata = mdata->next;
	}
	set_metadata(size, mdata, NULL);
	return (mdata + 1);
}

void	*first_malloc(size_t size)
{
	t_page *page;

	g_firstpage = page_push(g_firstpage, size, get_sizetype(size));
	page = g_firstpage;
	page->size += size + sizeof(t_mdata);
	return (init_block(page->start, size));
}

void	*do_malloc(size_t size)
{
	t_page	*page;

	if (get_sizetype(size) == LARGE)
		return (malloc_large(size));
	else if (!g_firstpage)
		return (first_malloc(size));
	else if ((page = find_page(size)) != NULL)
		return (init_block(page->start, size));
	page = page_push(g_firstpage, size, get_sizetype(size));
	page->size += size + sizeof(t_mdata);
	return (init_block(page->start, size));
}
