/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_radix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:39:19 by miandres          #+#    #+#             */
/*   Updated: 2026/02/01 07:40:00 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_num **stack_1, t_num **stack_2)
{
	t_num	*tmp;

	if (!stack_1 || !(*stack_1))
		return ;
	tmp = *stack_1;
	*stack_1 = tmp->next;
	tmp->next = *stack_2;
	*stack_2 = tmp;
}

void	pa(t_num **a, t_num **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_num **a, t_num **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	ra(t_num **a)
{
	t_num	*old_first;
	t_num	*old_last;
	
	if (!a || !(*a) || !(*a)->next)
		return ;
	old_first = *a;
	*a = old_first->next;
	old_first->next = NULL;
	old_last = *a;
	while (old_last->next)
		old_last = old_last->next;
	old_last->next = old_first;
	write(1, "ra\n", 3);
}
