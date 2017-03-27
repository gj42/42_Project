/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:45:20 by bciss             #+#    #+#             */
/*   Updated: 2016/05/11 21:46:57 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcpy(char *dst, const char *src, size_t size)
{
	int i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while (src[i] != '\0' && (size - 1))
	{
		dst[i] = src[i];
		size--;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
