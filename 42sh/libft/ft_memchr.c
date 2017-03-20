/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:31:16 by bciss             #+#    #+#             */
/*   Updated: 2014/12/27 18:23:53 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	int				i;
	unsigned char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	a = c;
	while ((i < (int)n))
	{
		if (str[i] == a)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
