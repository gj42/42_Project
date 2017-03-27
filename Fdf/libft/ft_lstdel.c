/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 13:54:53 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/18 14:20:24 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*talst;
	t_list	*tnext;

	if (alst && *alst && del)
	{
		talst = *alst;
		while (talst)
		{
			del(talst->content, talst->content_size);
			tnext = talst->next;
			free(talst);
			talst = tnext;
		}
		*alst = NULL;
	}
}
