/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 23:19:59 by gjensen           #+#    #+#             */
/*   Updated: 2015/01/21 23:20:07 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_quicksort(void *base, int start, int end)
{
	int			left;
	int			right;
	const void	*pivot;

	left = start - 1;
	end = right - 1;
	pivot = base[start];
	if (start >= end)
		return (base);
	while (left < right)
	{
		while (base[right] > pivot)
			right--;
		while (argv[left] < pivot)
			left++;
		if (left < right)
			ft_swap(left, right);
	}
	base = ft_quicksort(base, start, right);
	base = ft_quicksort(base, right + 1, end);
	return (base);
}
