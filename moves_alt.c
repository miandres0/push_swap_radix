/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_alt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:33:58 by miandres          #+#    #+#             */
/*   Updated: 2026/02/01 07:40:42 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_num **stack)
{
	t_num	*first;
	t_num	*second;
	
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*stack) = second;
}

void	sa(t_num **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_num **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	rra(t_num **a)
{
	t_num	*old_last;
	t_num	*new_last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	old_last = *a;
	while (old_last->next)
	{
		new_last = old_last;
		old_last = old_last->next;
	}
	new_last->next = NULL;
	old_last->next = *a;
	*a = old_last;
	write(1, "rra\n", 4);
}
