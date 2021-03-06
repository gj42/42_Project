/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 02:00:04 by gjensen           #+#    #+#             */
/*   Updated: 2016/03/02 02:28:42 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**g_env;

void	free_env(void)
{
	char	**head;
	char	**tmp;
	char	*var;

	if (!g_env)
		return ;
	head = g_env;
	tmp = g_env;
	while (*tmp)
	{
		var = *tmp++;
		free(var);
		var = NULL;
	}
	free(head);
	head = NULL;
}
