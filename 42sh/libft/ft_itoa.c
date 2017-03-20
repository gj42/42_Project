/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:53:51 by bciss             #+#    #+#             */
/*   Updated: 2014/11/16 20:46:28 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	unsigned int	i;

	i = 0;
	if (n == -2147483648)
		n++;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	num;
	char			*str;
	int				sign;

	sign = (n < 0 ? -1 : 1);
	num = (n < 0 ? -n : n);
	len = (n < 0 ? ft_intlen(n) + 1 : ft_intlen(n));
	if ((str = ft_strnew(len + 1)) == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	else
	{
		while (num > 0)
		{
			str[len-- - 1] = ((char)(num % 10) + '0');
			num /= 10;
		}
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
