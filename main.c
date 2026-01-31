/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:01:15 by miandres          #+#    #+#             */
/*   Updated: 2026/01/31 14:49:24 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_rank(int *array, int size, int i)
{
	int	j;
	int	rank;

	rank = 0;
	j = 0;
	while (j < size)
	{
		if (array[j] < array[i])
			rank++;
		j++;
	}
	return (rank);
}
t_num	*create_stack_a(int *array, int size)
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
}


int main(int argc, char **argv)
{
	// int		*array;
	// int		size;
	int		array[] = {1, 3, 2, 8, 4, 7, 5, 6};
	int		size = 8;
	t_num	*stack_a;
	t_num	*stack_b;
	
	// array = 
	// if (check_argv)
	// 	return (1); // erro, print sla oq
	// size = create_array(argc, argv, &array);
	stack_b = NULL;
	stack_a = create_stack_a(array, size);
	radix_sort(&stack_a, &stack_b, size);
	return (0);
}
