/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:32:21 by gjensen           #+#    #+#             */
/*   Updated: 2016/05/12 15:32:24 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*g_command;
int		g_status;
int		g_size;
int		g_pipe;
int		g_opts;
char	g_history_file[MAXPATHLEN];
char	**g_new_env;
char	g_history_string[0xf000];
struct s_hist *g_history;

int		main(int ac, char **av, char **env)
{
	(void)ac;
	if (init(av, env) == -1)
		return (1);
	sh_signals();
	prompt();
	while (do_command())
		;
	denit();
	return (0);
}
