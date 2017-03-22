/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 23:50:44 by gjensen           #+#    #+#             */
/*   Updated: 2015/06/22 22:45:54 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	usage(char *str)
{
	printf("Usage %s <addr> <port>\n", str);
	exit(-1);
}

static int	create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;
	char				check[3];

	proto = getprotobyname("tcp");
	if (!proto)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) < 0)
		ft_putendl_fd("Connect error", 2), exit(2);
	if (read(sock, check, 3))
	{
		if (ft_strcmp(check, "ok") == 0)
			printf("Connected to server\n");
		else
			ft_putendl_fd("Server not listening, exit", 2), exit(0);
	}
	return (sock);
}

static void	ftp_recvstd(int sock)
{
	int		cr;
	int		eol;
	char	buf[2];

	cr = 0;
	eol = 0;
	while (!eol)
	{
		if ((recv(sock, buf, 1, 0)) < 0)
			break ;
		buf[1] = 0;
		if (buf[0] == '\r')
			cr = 1;
		else if (cr == 1 && buf[0] == '\n')
			eol = 1;
		else if (cr && buf[0] != '\n')
			cr = 0;
		ft_putchar(buf[0]);
	}
}

static void	ftp_clientmanage(int sock, char *addr, int port)
{
	char	*line;
	char	home[1024];
	char	*nl;
	char	**option;

	getcwd(home, 1024);
	printf("Client Home directory set at: %s\n", home);
	while (42)
	{
		ftp_cprompt(addr, port);
		if (get_next_line(0, &line) <= 0)
			exit(0);
		nl = ft_epur_tab(line);
		option = ft_strsplit(nl, ' ');
		if (ftp_client_cmd(sock, option, 0, home))
			ftp_recvstd(sock);
		ft_strdel(&line);
		if (nl)
			ft_strdel(&nl);
		if (option)
			ft_arrfree(&option);
	}
	close(sock);
}

int			main(int ac, char **av)
{
	int				port;
	int				sock;
	char			*addr;
	struct hostent	*host;

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	if (!(host = gethostbyname(av[1])))
	{
		ft_putendl_fd("Ip error", 2);
		return (0);
	}
	addr = inet_ntoa(*((struct in_addr**)host->h_addr_list)[0]);
	sock = create_client(addr, port);
	ftp_clientmanage(sock, addr, port);
	return (0);
}
