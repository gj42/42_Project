/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:44:50 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/13 18:47:01 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*dst;
	char	*src;

	dst = s1;
	src = (char*)s2;
	if (dst && src)
	{
		while (*dst)
			++dst;
		while (*src)
			*dst++ = *src++;
		*dst = 0;
	}
	return (s1);
}
