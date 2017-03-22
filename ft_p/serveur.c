/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 15:51:20 by gjensen           #+#    #+#             */
/*   Updated: 2015/06/22 20:04:38 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	usage(char *str)
{
	printf("Usage %s <port>\n", str);
	exit(-1);
}

static void	ftp_sig_to_wait(int signum)
{
	if (signum != 20)
		return ;
	wait4(-1, 0, WNOHANG, 0);
}

int			main(int ac, char **av)
{
	int	port;
	int	sock;

	if (ac != 2)
		usage(av[0]);
	signal(SIGCHLD, ftp_sig_to_wait);
	if (!(port = ft_atoi(av[1])))
	{
		ft_putendl_fd("Invalid Port", 2);
		return (0);
	}
	sock = create_server(port);
	ftp_acceptclient(sock);
	close(sock);
	return (0);
}
