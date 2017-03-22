/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 16:14:27 by vdaviot           #+#    #+#             */
/*   Updated: 2016/03/07 23:18:28 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinarray(char **av)
{
	char	*ret;
	int		i;

	i = 1;
	ret = av[0];
	while (av[i])
	{
		ft_strcat(ret, " ");
		ft_strcat(ret, av[i]);
		i++;
	}
	return (ret);
}