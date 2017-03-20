/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:32:21 by bciss             #+#    #+#             */
/*   Updated: 2016/05/17 00:54:42 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*g_command;
int		g_status;
char	**g_local;
char	**g_tb_hist;
int		g_size;
int		g_pipe;
int		g_opts;
int		g_hist;
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
