/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 22:17:30 by bciss             #+#    #+#             */
/*   Updated: 2016/05/05 00:56:38 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include "ft_sh.h"
#include <sys/wait.h>
#include <unistd.h>

int		run_pipe(char *left, char *right)
{
	int		fildes[2];
	pid_t	pid;

	pipe(fildes);
	pid = fork();
	if (pid == -1)
	{
		close(fildes[0]);
		close(fildes[1]);
		exit(0);
	}
	else if (pid == 0)
	{
		close(fildes[0]);
		dup2(fildes[1], 1);
		ft_traitement(left);
		exit(0);
	}
	dup2(fildes[0], 0);
	close(fildes[1]);
	ft_traitement(right);
	exit(0);
	return (1);
}

int		ft_pipe(char *left, char *right)
{
	pid_t	pid;

	g_pipe = 1;
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
		return (run_pipe(left, right));
	else
		wait(NULL);
	return (0);
}
