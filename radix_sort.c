/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:58:04 by miandres          #+#    #+#             */
/*   Updated: 2026/02/01 10:35:46 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bit(int n)
{
	int	bits;

	bits = 0;
	while (n)
	{
		bits++;
		n = n >> 1;
	}
	return (bits);
}

void	radix_sort(t_num **a, t_num **b, int size)
{
	int	i;
	int	j;
	int	max_bit;

	max_bit = get_max_bit(size - 1);
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->rank >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
