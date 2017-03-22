/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 18:30:12 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/22 18:18:15 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ret;
	size_t		slen1;
	size_t		slen2;

	ret = NULL;
	if (s1 && s2)
	{
		slen1 = ft_strlen(s1);
		slen2 = ft_strlen(s2);
		if ((ret = (char*)malloc(slen1 + slen2 + 1)) == NULL)
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strcat(ret, s2);
	}
	return (ret);
}
