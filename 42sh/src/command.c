/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 09:28:27 by bciss             #+#    #+#             */
/*   Updated: 2016/05/31 22:09:52 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "get_next_line.h"

static	void	set_next_command(void)
{
	write(1, "\n", 1);
	prompt();
}

void			execute_command(char *str)
{
	int		i;
	char	**tb;
	char	*tmp;

	if ((!str) || ((str = ft_formatting(str)) == NULL) ||
			(!(tb = ft_smartsplit(str, ';'))))
		return ;
	if (str[0] == '!' && ft_isnumber(str + 1))
	{
		builtin_history(tb);
		return ;
	}
	i = -1;
	while (tb[++i])
	{
		tmp = ft_strdup(tb[i]);
		pre_red(tmp);
		ft_strremovechars(tmp, ' ');
		if (tb[i][0] != '\n' && ft_strlen(tmp) > 0)
			ft_traitement(tb[i]);
		ft_strdel(&tmp);
	}
	ft_strdel(&str);
	if (tb)
		ft_arrfree(&tb);
}

static char		*ask_command(void)
{
	static char command[0xf000];
	char		*ptr;

	g_command = command;
	ft_bzero(command, 0xf000);
	if (g_history_string[0])
	{
		ft_strlcpy(command, g_history_string, 0xf000);
		command[ft_strlen(command) - 1] = ' ';
		ft_strcatf(command, command, 10);
		ft_refresh(command, ft_strlen(command) - 1);
		ft_bzero(g_history_string, 0xf000);
		ptr = command;
	}
	else
		ptr = command;
	while (ptr[ft_strlen(ptr) - 1] != '\n')
		if (!(ptr = ft_strlcpy(ptr, ft_edit_and_history(ptr), 0xf000)))
			return (NULL);
	g_hist = 0;
	return (ft_strdup(command));
}

int				do_command(void)
{
	char	*str;
	char	*ret;

	str = ask_command();
	if (str == NULL)
		get_next_line(0, &str);
	g_new_env = NULL;
	execute_command(str);
	set_next_command();
	ret = ft_itoa(!g_status);
	sh_builtin_setenv_mng("?", ret, &g_local);
	ft_strdel(&ret);
	ft_strdel(&str);
	return (1);
}

void			ft_error(char *str)
{
	write(2, &str, ft_strlen(str));
}
