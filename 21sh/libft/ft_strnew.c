/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:51:12 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/27 18:42:33 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	{
		if ((str = (char*)ft_memalloc(sizeof(char) * size + 1)) == NULL)
			return (NULL);
		ft_bzero(str, size);
	}
	return (str);
}
