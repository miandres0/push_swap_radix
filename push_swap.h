/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:43:33 by miandres          #+#    #+#             */
/*   Updated: 2026/01/31 14:54:33 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_num
{
	int		rank;
	struct s_num	*next;
}	t_num;

t_num	*create_stack_a(int *array, int size);
int		find_rank(int *array, int size, int i);
void	radix_sort(t_num **a, t_num **b, int size);
int		get_max_bit(int n);
void	push(t_num **stack_1, t_num **stack_2);
void	pa(t_num **a, t_num **b);
void	pb(t_num **a, t_num **b);
void	ra(t_num **a);
t_num	*ft_lstnew(int content);
void	lst_add_back(t_num **lst, t_num *new);

#endif
