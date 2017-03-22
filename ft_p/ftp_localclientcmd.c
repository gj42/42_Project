/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_localclientcmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 17:28:05 by gjensen           #+#    #+#             */
/*   Updated: 2015/06/22 22:09:42 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	ftp_builtin_lls(char **av)
{
	pid_t	father;

	free(av[0]);
	av[0] = ft_strdup("/bin/ls");
	ft_putendl("Local list:");
	father = fork();
	if (father != -1)
	{
		if (father == 0)
		{
			if (execv(av[0], av) == -1)
				ft_putendl_fd("Format error", 2);
			exit (0);
		}
		else
			wait4(father, 0, 0, 0);
	}
}

static void	ftp_builtin_lcd(char **av, char *home)
{
	char	*cmd;
	char	pwd[1024];

	cmd = av[1];
	if (ft_arrlen(av) > 2)
	{
		ft_putendl_fd("lcd: too many arguments", 2);
		return ;
	}
	if (ft_arrlen(av) == 1 || (cmd && (ft_strcmp(cmd, "~") == 0)))
		cmd = home;
	if (access(cmd, F_OK) == 0)
	{
		if (ftp_isbin(cmd) == 1 || ftp_isbin(cmd) == 3)
		{
			if (chdir(cmd) != 0)
				ft_putendl_fd("Error", 2);
			getcwd(pwd, 1024);
			printf("Current local directory: %s\n", pwd);
		}
		else
			ft_putendl_fd("Error: lcd: not a directory", 2);
	}
	else
		ft_putendl_fd("Error: lcd: no such file or directory", 2);
}

static void	ftp_builtin_lpwd(void)
{
	char	pwd[1024];

	getcwd(pwd, 1024);
	printf("Current local directory: %s\n", pwd);
}

int			ftp_local_cmd(char **cmd, char *home)
{
	int state;

	state = 0;
	if (ft_strcmp(ft_tomin(cmd[0]), "lls") == 0)
		ftp_builtin_lls(cmd), state = 1;
	else if (ft_strcmp(ft_tomin(cmd[0]), "lcd") == 0)
		ftp_builtin_lcd(cmd, home), state = 1;
	else if (ft_strcmp(ft_tomin(cmd[0]), "lpwd") == 0)
		ftp_builtin_lpwd(), state = 1;
	return (state);
}
