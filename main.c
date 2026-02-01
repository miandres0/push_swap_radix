/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:01:15 by miandres          #+#    #+#             */
/*   Updated: 2026/02/01 10:34:46 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_num *stack)
{
	t_num	*i;
	t_num	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->number == j->number)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

int	check_order(t_num *stack)
{
	t_num	*i;
	t_num	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->number > j->number)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

void	rank_list_values(t_num *stack)
{
	int		rank;
	t_num	*i;
	t_num	*j;

	i = stack;
	while (i)
	{
		rank = 0;
		j = stack;
		while (j)
		{
			if (j->number < i->number)
				rank++;
			j = j->next;
		}
		i->rank = rank;
		i = i->next;
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
