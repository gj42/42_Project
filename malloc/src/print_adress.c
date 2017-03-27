/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:21:41 by gjensen           #+#    #+#             */
/*   Updated: 2016/12/12 15:57:46 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static uint64_t	is_pow16(size_t pow)
{
	uint64_t	nb;
	size_t		i;

	i = 0;
	nb = 1;
	while (i < pow && nb <= 1152921504606846976)
	{
		nb = nb * 16;
		i++;
	}
	return (nb);
}

static char		get_char(int n)
{
	if (n < 10)
		return (n + '0');
	n -= 10;
	return (n + 'A');
}

static void		print_number(uint64_t nb, size_t num_digit, char *buff)
{
	size_t		i;
	int			temp;
	uint64_t	quotient;

	quotient = nb;
	i = num_digit - 1;
	while (quotient != 0)
	{
		temp = quotient % 16;
		buff[i] = get_char(temp);
		i--;
		quotient = quotient / 16;
	}
	buff[num_digit] = 0;
}

void			ft_itoa_hex(uint64_t n, char *buff)
{
	size_t		num_digit;
	uint64_t	nb;

	num_digit = 1;
	nb = n;
	if (n > 1152921504606846976)
		num_digit = 15;
	else
	{
		while (is_pow16(num_digit) <= nb)
			num_digit++;
	}
	print_number(nb, num_digit, buff);
}

void			print_adress(void *addr)
{
	char	buff[20];

	ft_bzero(buff, 20);
	ft_itoa_hex((uint64_t)addr, buff);
	ft_putstr("0x");
	ft_putstr(buff);
}
