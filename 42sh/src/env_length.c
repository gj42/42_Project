/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 01:57:22 by bciss             #+#    #+#             */
/*   Updated: 2016/01/14 06:01:02 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	env_length(char **env)
{
	size_t	len;

	len = 0;
	while (*env++)
		len++;
	return (len);
}
