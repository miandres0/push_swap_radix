/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:43:33 by miandres          #+#    #+#             */
/*   Updated: 2026/02/01 07:41:56 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_num
{
	int				number;
	int				rank;
	struct s_num	*next;
}	t_num;

void	rank_list_values(t_num *stack);
int		check_duplicatese(t_num *stack);

t_num	*parse_args(int argc, char **argv);
int		parse_argument(char	*str, t_num **stack);
int		create_node(char *s, t_num **stack);
int		is_valid_number(char *s);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);

void	radix_sort(t_num **a, t_num **b, int size);
int		get_max_bit(int n);
void	alt_sort(t_num **a, t_num **b, int size);
void	case_two(t_num **a);
void	case_three(t_num **a);
void	case_four(t_num **a, t_num **b);
void	case_five(t_num **a, t_num **b);
void	move_to_top(t_num **a, int rank, int size);
int		find_position(t_num *stack, int rank);
void	push(t_num **stack_1, t_num **stack_2);
void	pa(t_num **a, t_num **b);
void	pb(t_num **a, t_num **b);
void	ra(t_num **a);
void	swap(t_num **stack);
void	sa(t_num **a);
void	sb(t_num **b);
void	rra(t_num **a);
t_num	*ft_lstnew(int content);
void	lst_add_back(t_num **lst, t_num *new);
int		ft_lstsize(t_num *lst);
void	free_stack(t_num **stack);
void	free_split(char **array);

// ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG

#endif
