/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 11:53:49 by gjensen           #+#    #+#             */
/*   Updated: 2014/12/17 15:55:32 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int number)
{
	int lenght;

	lenght = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		lenght++;
	while (number != 0)
	{
		lenght++;
		number = number / 10;
	}
	return (lenght);
}
