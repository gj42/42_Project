/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:33:08 by gjensen           #+#    #+#             */
/*   Updated: 2014/12/17 14:16:07 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;

	ret = NULL;
	if (size)
	{
		if ((ret = (void*)malloc(size)) == NULL)
			return (NULL);
		ft_bzero(ret, size);
	}
	return (ret);
}
