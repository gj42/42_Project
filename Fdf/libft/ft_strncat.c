/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:37:15 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/15 19:55:15 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*dst;
	char	*src;

	dst = s1;
	src = (char*)s2;
	if (dst && src)
	{
		while (*dst)
			++dst;
		while (*src && n--)
			*dst++ = *src++;
		*dst = 0;
	}
	return (s1);
}
