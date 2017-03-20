/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:59:02 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 03:03:10 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlchr(const char *s, int c, size_t size)
{
	char	*str;

	str = (char *)s;
	while (*str != c && size > 0)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		size--;
		str++;
	}
	return (str);
}
