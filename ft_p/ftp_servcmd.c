/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_servcmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 17:38:43 by gjensen           #+#    #+#             */
/*   Updated: 2015/06/22 20:42:47 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	ftp_pwdcmd(int cs, char *home)
{
	char	pwd[1024];
	char	*offsetpath;

	getcwd(pwd, 1024);
	dup2(cs, STDOUT_FILENO);
	dup2(cs, STDERR_FILENO);
	if ((offsetpath = ft_strstr(pwd, home)) &&
			(ft_strlen(offsetpath) > ft_strlen(home)))
		offsetpath = pwd + ft_strlen(home);
	else
		offsetpath = "/";
	ft_putchar('\"');
	ft_putstr(offsetpath);
	ft_putchar('\"');
	ft_putstr("\nSUCCESS: Current directory sent");
	dup2(STDIN_FILENO, STDOUT_FILENO);
	dup2(STDIN_FILENO, STDERR_FILENO);
	send(cs, "\r\n", 2, 0);
}

static void	ftp_lscmd(int cs, char *buf)
{
	pid_t	pid;
	char	*opt;

	opt = ftp_opt_ls(buf);
	dup2(cs, STDOUT_FILENO);
	dup2(cs, STDERR_FILENO);
	pid = fork();
	if (pid != -1)
	{
		if (pid == 0)
		{
			if (execl("/bin/ls", "/bin/ls", opt) == -1)
				return (ft_putendl_fd("ERROR: Can't send list", 2));
			exit (0);
		}
		else
			wait4(pid, 0, 0, 0);
	}
	ft_putstr("SUCCESS: Directory list succesfully sent");
	dup2(STDIN_FILENO, STDOUT_FILENO);
	dup2(STDIN_FILENO, STDERR_FILENO);
	send(cs, "\r\n", 2, 0);
}

static void	ftp_cd_open(char *dir, char *home, int cs)
{
	char	pwd[1024];

	if (chdir(dir) == 0)
	{
		getcwd(pwd, 1024);
		if (!(ft_strstr(pwd, home)))
		{
			if (chdir(home) == 0)
				write(cs, "scc\0", 4);
			else
				write(cs, "err\0", 4);
		}
		else
			write(cs, "scc\0", 4);
	}
	else
		write(cs, "err\0", 4);
}

static void	ftp_cwdcmd(int cs, char *buf, char *home)
{
	char	**cmd;

	cmd = ft_strsplit(buf, ' ');
	if (ft_arrlen(cmd) > 2)
	{
		write(cs, "arg\0", 4), ft_arrfree(&cmd);
		return ;
	}
	if (ft_arrlen(cmd) == 1)
	{
		chdir(home), write(cs, "scc\0", 4), ft_arrfree(&cmd);
		return ;
	}
	else if (access(cmd[1], F_OK) == 0)
	{
		if (ftp_isbin(cmd[1]) == 1 || ftp_isbin(cmd[1]) == 3)
			ftp_cd_open(cmd[1], home, cs);
		else
			write(cs, "nof\0", 4);
	}
	else
		write(cs, "nof\0", 4);
	ft_arrfree(&cmd);
}

void		ftp_read_socket(int cs)
{
	char	buf[1024];
	int		r;
	char	home[1024];

	write(cs, "ok\0", 3);
	getcwd(home, 1024);
	while ((r = read(cs, buf, 1023)) > 0)
	{
		buf[r] = 0;
		if (ft_strncmp("LIST", buf, 4) == 0)
			ftp_lscmd(cs, buf);
		else if (ft_strncmp("PWD", buf, 3) == 0)
			ftp_pwdcmd(cs, home);
		else if (ft_strncmp("QUIT", buf, 4) == 0)
			return ;
		else if (ft_strncmp("CWD", buf, 3) == 0)
			ftp_cwdcmd(cs, buf, home);
		else if (ft_strncmp("STOR", buf, 4) == 0)
			ftp_putcmd(cs, buf);
		else if (ft_strncmp("RETR", buf, 4) == 0)
			ftp_getcmd(cs, buf);
	}
}
