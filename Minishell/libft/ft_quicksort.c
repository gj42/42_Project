/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 13:20:22 by gjensen           #+#    #+#             */
/*   Updated: 2015/01/28 16:05:22 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_quicksort(int *base, int start, int end)
{
	int		left;
	int		right;
	int		pivot;

	left = start - 1;
	right = end + 1;
	pivot = base[start];
	if (start >= end)
		return (base);
	while (left < right)
	{
		right--;
		while (base[right] > pivot)
			right--;
		left++;
		while (base[left] < pivot)
			left++;
		if (left < right)
			ft_swapint(&base[left], &base[right]);
	}
	base = ft_quicksort(base, start, right);
	base = ft_quicksort(base, right + 1, end);
	return (base);
}
