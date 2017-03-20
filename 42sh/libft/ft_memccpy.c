/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:22:43 by bciss             #+#    #+#             */
/*   Updated: 2014/11/15 19:17:30 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*a;
	const char	*b;

	b = src;
	a = dst;
	while (n--)
	{
		if (*b == c)
		{
			*a++ = *b++;
			return (a);
		}
		*a++ = *b++;
	}
	return (NULL);
}
