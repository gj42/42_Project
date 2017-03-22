/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createserv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 21:47:05 by gjensen           #+#    #+#             */
/*   Updated: 2015/06/22 16:33:25 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	ftp_acceptclient(int sock)
{
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	pid_t				cpid;

	while (42)
	{
		cslen = sizeof(csin);
		if ((cs = accept(sock, (struct sockaddr*)&csin, &cslen)) > 0)
			printf("[%s:%d] connected\n", inet_ntoa(csin.sin_addr),
					ntohs(csin.sin_port));
		cpid = fork();
		if (cpid == 0)
		{
			ftp_read_socket(cs);
			printf("[%s:%d] disconnected\n", inet_ntoa(csin.sin_addr),
					ntohs(csin.sin_port));
			close(sock);
			close(cs);
			exit(0);
		}
		else
			close(cs);
	}
}

int		create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) < 0)
		ft_putendl_fd("Bind error", 2), exit(2);
	if (listen(sock, 42) == -1)
		ft_putendl_fd("Listen error", 2), exit (2);
	return (sock);
}
