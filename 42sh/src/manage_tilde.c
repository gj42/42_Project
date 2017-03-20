/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:17:51 by bciss             #+#    #+#             */
/*   Updated: 2016/05/20 16:21:50 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <pwd.h>
#include <sys/types.h>

char		*ft_check_tild(char **str)
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

char		*ft_found_or_not(char **str, char *tmp, int i)
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
		ft_putstr_fd("42sh"": no such user or named directory: ", 2);
		ft_putendl_fd(user, 2);
		ft_strdel(str);
		return (NULL);
	}
	return (*str);
}

char		*manage_tilde(char *str)
{
	char	*tmp;
	int		i;

	tmp = ft_check_tild(&str);
	if (tmp != NULL)
		return (tmp);
	i = -1;
	tmp = ft_found_or_not(&str, tmp, i);
	return (tmp);
}

static void	sh_add_variable(char **parsed)
{
	int		i;
	char	*name;
	char	*value;

	i = 0;
	while (parsed[i])
	{
		name = ft_strdupc(parsed[i], '=');
		value = ft_strchr(parsed[i], '=') + 1;
		if (sh_get_env(name, g_env))
			sh_builtin_setenv_mng(name, value, &g_env);
		else
			sh_builtin_export_mng(name, value, &g_local);
		ft_strdel(&name);
		i++;
	}
}

char		**sh_handle_equal_var(char **parsed)
{
	int		i;
	int		n;
	char	**tmp;

	if (parsed[0] == NULL)
		return (parsed);
	i = -1;
	n = 0;
	while (parsed[++i])
	{
		if (ft_strchr(parsed[i], '=') && parsed[i][0] != '=')
			n++;
		else
			break ;
	}
	if (n == ft_arrlen(parsed) && ft_strchr(parsed[0], '=') &&
			parsed[0][0] != '=')
		sh_add_variable(parsed);
	if ((tmp = (char **)malloc(sizeof(char *) * (n + 1))) == NULL)
		return (parsed);
	tmp = ft_arrcpy(&parsed[i]);
	ft_arrfree(&parsed);
	return (tmp);
}
