/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 19:16:30 by gjensen           #+#    #+#             */
/*   Updated: 2015/06/18 19:16:38 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
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
	free(s1);
	return (ret);
}
