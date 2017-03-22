/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:00:21 by vdaviot           #+#    #+#             */
/*   Updated: 2015/01/10 23:52:40 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*mem;
	unsigned int	counter;
	char			*str;

	counter = 0;
	if (!(mem = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	str = (char *)mem;
	if (mem != NULL)
	{
		while (counter++ < size)
			*str++ = 0;
	}
	return (mem);
}
