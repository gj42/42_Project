/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:59:17 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/14 17:11:49 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buf;

	buf = (char*)s;
	if (buf)
	{
		while (*buf)
			buf++;
		if ((char)c == 0)
			return (buf);
		while (buf >= s)
		{
			if (*buf == (char)c)
				return (buf);
			buf--;
		}
	}
	return (NULL);
}
