/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 16:07:42 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/18 17:03:58 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*ret;
	t_list	*prev;
	t_list	*telem;

	ret = NULL;
	if (lst && f)
	{
		ret = f(lst);
		prev = ret;
		lst = lst->next;
		while (lst)
		{
			if ((telem = f(lst)) == NULL)
				return (NULL);
			prev->next = telem;
			prev = telem;
			lst = lst->next;
		}
		prev->next = NULL;
	}
	return (ret);
}
