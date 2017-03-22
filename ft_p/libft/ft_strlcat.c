/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 20:51:29 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/17 14:48:16 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t i;
	size_t j;

	if (dst && src)
	{
		len = ft_strlen(src);
		j = 0;
		i = 0;
		while (dst[i] && i < size)
			i++;
		if (size > 0)
			while (i < size - 1 && src[j])
				dst[i++] = src[j++];
		if (j > 0)
		{
			dst[i] = 0;
			return (len + i - j);
		}
		return (len + i);
	}
	return (0);
}
