/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 22:17:41 by bciss             #+#    #+#             */
/*   Updated: 2014/11/09 22:04:04 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = ft_memalloc(i);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = ((*f)(i, s[i]));
		i++;
	}
	return (str);
}
