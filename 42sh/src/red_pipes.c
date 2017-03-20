/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 20:11:11 by bciss             #+#    #+#             */
/*   Updated: 2016/05/31 21:35:49 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	pipe_fork_err(int a, int b)
{
	close(a);
	close(b);
	exit(0);
}

void	blue_pipe(char *ll, char *right)
{
	pid_t	pid;
	int		fildes[2];

	if (ll[0] != '\0')
	{
		pipe(fildes);
		pid = fork();
		if (pid == -1)
			pipe_fork_err(fildes[0], fildes[1]);
		else if (pid == 0)
		{
			dup2(fildes[1], 1);
			close(fildes[0]);
			ft_putstr(ll);
			exit(0);
		}
		dup2(fildes[0], 0);
		close(fildes[1]);
	}
	ft_traitement(right);
	exit(0);
}

void	check_pid(int fildes[2], t_data d, char *ll, char *left)
{
	pid_t	pid;

	pipe(fildes);
	pid = fork();
	if (pid == -1)
		pipe_fork_err(fildes[0], fildes[1]);
	else if (pid == 0)
	{
		dup2(fildes[1], d.aggre[d.i]);
		close(fildes[0]);
		blue_pipe(ll, left);
		exit(0);
	}
}

void	red_pipe(char *left, t_data d, char *ll)
{
	int		fildes[2];
	char	buf[2048];
	int		ret;
	int		i;

	i = -1;
	if (left[0] != '\0')
	{
		if (d.fd[0] == 0)
			d.fd[0] = 1;
		while (d.fd[++i])
		{
			d.i = i;
			check_pid(fildes, d, ll, left);
			dup2(fildes[0], 0);
			close(fildes[1]);
			while ((ret = read((fildes[0]), buf, 2047)) > 0)
				write(d.fd[i], buf, ret);
		}
	}
	exit(0);
}
