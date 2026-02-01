/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_sort_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 02:07:40 by miandres          #+#    #+#             */
/*   Updated: 2026/02/01 10:33:21 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_num *stack, int rank)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->rank == rank)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	move_to_top(t_num **a, int rank, int size)
{
	int	position;
	int	reverse;

	position = find_position(*a, rank);
	if (position < 0)
		return ;
	if (position <= (size / 2))
	{
		while (position)
		{
			ra(a);
			position--;
		}
	}
	else
	{
		reverse = size - position;
		while (reverse)
		{
			rra(a);
			reverse--;
		}
	}
}
