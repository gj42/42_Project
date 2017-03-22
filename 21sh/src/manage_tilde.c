/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:17:51 by gjensen           #+#    #+#             */
/*   Updated: 2016/05/08 20:50:18 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <pwd.h>
#include <sys/types.h>

char	*ft_check_tild(char **str)
{
	char	*val;

	if (ft_strlen(*str) == 1)
	{
		val = sh_get_env_var("HOME");
		ft_strdel(str);
		if (val)
			return (ft_strdup(val));
		else
			return (ft_strdup(""));
	}
	return (NULL);
}

char	*ft_found_or_not(char **str, char *tmp, int i)
{
	struct passwd	*usp;
	char			user[0xF000];
	char			ret[0xF000];

	ft_bzero(user, 0xF000);
	tmp = *str + 1;
	while (tmp[++i])
		user[i] = tmp[i];
	tmp[i] = 0;
	if ((usp = getpwnam(user)) != NULL)
	{
		ft_strcpy(ret, usp->pw_dir);
		ft_strcat(ret, *str + i + 1);
		ft_strdel(str);
		*str = ft_strdup(ret);
	}
	else
	{
		ft_putstr_fd("21sh"": no such user or named directory: ", 2);
		ft_putendl_fd(user, 2);
		ft_strdel(str);
		return (NULL);
	}
	return (*str);
}

char	*manage_tilde(char *str)
{
	char			*tmp;
	int				i;

	tmp = ft_check_tild(&str);
	if (tmp != NULL)
		return (tmp);
	i = -1;
	tmp = ft_found_or_not(&str, tmp, i);
	return (tmp);
}
