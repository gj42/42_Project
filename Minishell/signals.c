/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/26 20:29:35 by gjensen           #+#    #+#             */
/*   Updated: 2015/06/11 21:07:59 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

pid_t		save_cpid(pid_t *father)
{
	static pid_t save;

	if (father)
	{
		save = *father;
		return (0);
	}
	else
		return (save);
}

static void	sh_signal_handle(int signum)
{
	char	**env;
	pid_t	cpid;

	env = sh_save_env(NULL);
	cpid = save_cpid(NULL);
	if (signum == SIGINT)
	{
		if (!cpid)
		{
			if (env)
			{
				ft_putchar('\n');
				sh_prompt(&env);
			}
		}
	}
}

static void	sh_sig_to_exit(int signum)
{
	char	**env;
	pid_t	cpid;

	env = sh_save_env(NULL);
	cpid = save_cpid(NULL);
	signal(signum, SIG_DFL);
	if (cpid)
	{
		ft_putstr("Due to sig ");
		ft_putnbr(signum);
		ft_putstr(", Minishell son's PID ");
		ft_putnbr(cpid);
		ft_putendl("killed.");
		kill(cpid, signum);
	}
	kill(getpid(), signum);
}

static void	sh_signals2(void)
{
	signal(SIGVTALRM, sh_sig_to_exit);
	signal(SIGPROF, sh_sig_to_exit);
	signal(SIGWINCH, SIG_IGN);
	signal(SIGINFO, SIG_IGN);
	signal(SIGUSR1, sh_sig_to_exit);
	signal(SIGUSR2, sh_sig_to_exit);
}

void		sh_signals(void)
{
	signal(SIGINT, sh_signal_handle);
	signal(SIGHUP, sh_sig_to_exit);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGILL, sh_sig_to_exit);
	signal(SIGTRAP, sh_sig_to_exit);
	signal(SIGABRT, sh_sig_to_exit);
	signal(SIGEMT, sh_sig_to_exit);
	signal(SIGFPE, sh_sig_to_exit);
	signal(SIGKILL, sh_sig_to_exit);
	signal(SIGBUS, sh_sig_to_exit);
	signal(SIGSEGV, sh_sig_to_exit);
	signal(SIGSYS, sh_sig_to_exit);
	signal(SIGPIPE, sh_sig_to_exit);
	signal(SIGALRM, sh_sig_to_exit);
	signal(SIGTERM, SIG_IGN);
	signal(SIGURG, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGIO, SIG_IGN);
	signal(SIGXCPU, sh_sig_to_exit);
	signal(SIGXFSZ, sh_sig_to_exit);
	sh_signals2();
}
