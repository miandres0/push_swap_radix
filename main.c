/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:01:15 by miandres          #+#    #+#             */
/*   Updated: 2026/01/31 21:22:59 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_num *stack)
{
	t_num	*i;
	t_num	*j;

	i = stack;
	while(i)
	{
		j = i->next;
		while(j)
		{
			if (i->number == j->number)
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
/* t_num	*create_stack_a(int *array, int size)
{
	int		i;
	int		rank;
	t_num	*lst;

	lst = NULL;
	i = 0;
	while (i < size)
	{
		rank = find_rank(array, size, i);
		lst_add_back(&lst, ft_lstnew(rank));
		i++;
	}
	return(lst);
} */

int main(int argc, char **argv)
{
	t_num	*stack_a;
	t_num	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	stack_a = parse_args(argc, argv);
	if (!stack_a || !check_duplicates(stack_a))
	{
		write(2, "Error\n", 6);
		return(1);
	}
	rank_list_values(stack_a);
	stack_b = NULL;
	size = ft_lstsize(stack_a);
	radix_sort(&stack_a, &stack_b, size);
	return (0);
}
