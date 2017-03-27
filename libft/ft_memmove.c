/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:32:02 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/11 13:44:11 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char*)malloc(sizeof(unsigned char) * len);
	ft_memcpy(temp, src, len);
	ft_memcpy(dst, temp, len);
	return (dst);
}
