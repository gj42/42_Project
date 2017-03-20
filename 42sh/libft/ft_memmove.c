/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:34:20 by bciss             #+#    #+#             */
/*   Updated: 2014/12/27 22:27:32 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;

	if ((!src) || (src == dst))
		return (dst);
	str = ft_memalloc(sizeof(unsigned char *) * len);
	str = ft_memcpy(str, src, len);
	dst = ft_memcpy(dst, str, len);
	free((void *)str);
	return (dst);
}
