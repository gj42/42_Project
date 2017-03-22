/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:07:59 by gjensen           #+#    #+#             */
/*   Updated: 2015/01/28 18:42:07 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	p;

	i = 0;
	p = (unsigned char)c;
	while (i < n)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		if (p == *(unsigned char*)src)
			return (dst + 1);
		dst++;
		src++;
		i++;
	}
	return (NULL);
}
