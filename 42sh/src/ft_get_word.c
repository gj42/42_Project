/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 00:25:00 by bciss             #+#    #+#             */
/*   Updated: 2016/03/07 23:22:50 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	increment_j(char *str, int i)
{
	if ((str[i] == ' ' || str[i] == '\t') &&
		(str[i - 1] != ' ' && str[i - 1] != '\t'))
		return (1);
	return (0);
}

char		*ft_get_word(char *str, int nb, int all)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 1;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] != '\0')
	{
		if (increment_j(str, i))
			j++;
		else if ((str[i] != ' ' && str[i] != '\t') && (j == nb) &&
			(i == 0 || (str[i - 1] == ' ' || str[i - 1] == '\t')))
		{
			if (all)
				return (ft_strdup(str + i));
			k = i;
			while (str[k] != '\0' && str[k] != '\t' && str[k] != ' ')
				k++;
			return (ft_strsub(str, i, k - i));
		}
		i++;
	}
	return (NULL);
}
