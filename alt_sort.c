/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 23:35:34 by miandres          #+#    #+#             */
/*   Updated: 2026/02/01 02:33:53 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_two(t_num **a)
{
	if ((*a)->rank > ((*a)->next)->rank)
		sa(a);
}

void	case_three(t_num **a)
{
	if ((*a)-> rank == 2)
		ra(a);
	else if (((*a)->next)->rank == 2)
		rra(a);
	if ((*a)->rank > ((*a)->next)->rank)
		sa(a);
}

void	case_four(t_num **a, t_num **b)
{
	move_to_top(a, 0, 4);
	pb(a, b);
	case_three(a);
	pa(a, b);
}

void	case_five(t_num **a, t_num **b)
{
	move_to_top(a, 0, 5);
	pb(a, b);
	move_to_top(a, 1, 4);
	pb(a, b);
	case_three(a);
	if ((*b)->rank < ((*b)->next)->rank)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	alt_sort(int size, t_num *a, t_num *b)
{
	if (size == 2)
		case_two(a);
	else if (size == 3)
		case_three(a);
	else if (size == 4)
		case_four(a, b);
	else if (size == 5)
	{
		case_five(a, b);
	}
}
