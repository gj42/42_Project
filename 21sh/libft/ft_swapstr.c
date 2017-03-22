/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 03:08:17 by vdaviot           #+#    #+#             */
/*   Updated: 2015/04/08 03:27:34 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapstr(char **str, char **str2)
{
	char	*tmp;

	tmp = ft_strdup(*str);
	*str = ft_strdup(*str2);
	*str2 = ft_strdup(*str);
	free(tmp);
}
