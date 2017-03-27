/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 04:02:10 by bciss             #+#    #+#             */
/*   Updated: 2015/01/12 19:10:00 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace_char(char *s, int find, int replace)
{
	char	*tmp;
	char	*ret;

	if (!s)
		return (NULL);
	tmp = ft_strnew(sizeof(s));
	ret = tmp;
	while (*s)
	{
		if (*s == find)
			*tmp = replace;
		else
			*tmp = *s;
		s++;
		tmp++;
	}
	return (ret);
}
