/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:01:15 by miandres          #+#    #+#             */
/*   Updated: 2026/02/01 10:51:29 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_num *stack)
{
	t_num	*node_1;
	t_num	*node_2;

	node_1 = stack;
	while (node_1)
	{
		node_2 = node_1->next;
		while (node_2)
		{
			if (node_1->number == node_2->number)
				return (0);
			node_2 = node_2->next;
		}
		node_1 = node_1->next;
	}
	return (1);
}

int	check_order(t_num *stack)
{
	t_num	*node_1;
	t_num	*node_2;

	node_1 = stack;
	while (node_1)
	{
		node_2 = node_1->next;
		while (node_2)
		{
			if (node_1->number > node_2->number)
				return (0);
			node_2 = node_2->next;
		}
		node_1 = node_1->next;
	}
	return (1);
}

void	rank_list_values(t_num *stack)
{
	int		rank;
	t_num	*node_1;
	t_num	*node_2;

	node_1 = stack;
	while (node_1)
	{
		rank = 0;
		node_2 = stack;
		while (node_2)
		{
			if (node_2->number < node_1->number)
				rank++;
			node_2 = node_2->next;
		}
		node_1->rank = rank;
		node_1 = node_1->next;
	}
}

int	main(int argc, char **argv)
{
	t_num	*stack_a;
	t_num	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	stack_a = parse_args(argc, argv);
	if (!stack_a || !check_duplicates(stack_a))
	{
		free_stack(&stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_order(stack_a))
		return (0);
	rank_list_values(stack_a);
	stack_b = NULL;
	size = ft_lstsize(stack_a);
	if (size <= 5)
		alt_sort(&stack_a, &stack_b, size);
	else
		radix_sort(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	return (0);
}
