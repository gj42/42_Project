/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:40:39 by gjensen           #+#    #+#             */
/*   Updated: 2016/12/12 16:00:24 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	*do_smaller_realloc(void *ptr, size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	ptr = ft_memcpy(tmp, ptr, size);
	return (ptr);
}

void	*do_bigger_realloc(t_mdata *mdata, size_t size, t_page *page, void *ptr)
{
	void	*tmp;

	if (page->size != LARGE)
	{
		if (mdata->next == NULL)
		{
			if ((page->size + size) < get_max_size(page->type, size))
			{
				mdata->size = size;
				return (ptr);
			}
		}
	}
	tmp = malloc(size);
	return (ft_memcpy(tmp, ptr, mdata->size));
}

void	*realloc(void *ptr, size_t size)
{
	t_page	*page;
	t_mdata	*mdata;

	if (!ptr)
		return (malloc(size));
	if (!size && ptr)
	{
		free(ptr);
		malloc(TINY_SIZE);
	}
	if ((page = find_pageptr(ptr)) == NULL)
		return (NULL);
	if ((mdata = find_mdataptr(ptr, page)) == NULL)
		return (NULL);
	if (size > mdata->size)
		return (do_bigger_realloc(mdata, size, page, ptr));
	else if (size < mdata->size)
		return (do_smaller_realloc(ptr, size));
	else
		return (ptr);
	return (NULL);
}
