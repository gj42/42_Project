/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 08:05:18 by gjensen           #+#    #+#             */
/*   Updated: 2016/01/14 08:06:40 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	minimal_prompt(void)
{
	tputs(tgetstr("md", NULL), 1, t_puts);
	write(1, BASIC_PROMPT, ft_strlen(BASIC_PROMPT));
	tputs(tgetstr("me", NULL), 1, t_puts);
}
