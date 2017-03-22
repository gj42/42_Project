/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 16:14:27 by gjensen           #+#    #+#             */
/*   Updated: 2015/05/09 17:10:14 by gjensen          ###   ########.fr       */
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
