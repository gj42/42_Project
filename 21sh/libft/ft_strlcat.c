/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:14:30 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/15 19:26:37 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			d;
	size_t			s;
	unsigned int	o;

	o = size;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	while (*dst && size)
	{
		dst++;
		size--;
	}
	if (!size)
		return (o + s);
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (d + s);
}
