/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:07:20 by miandres          #+#    #+#             */
/*   Updated: 2026/01/31 20:41:49 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	number;

	number = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 44 - str[i];
		i++;
	}
	while (str[i])
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (sign * number);
}

int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (2048);
	return (0);
}

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return(0);
		i++;
	}
	return (1);
}

int	create_node(char *s, t_num **stack)
{
	long	result;
	t_num	*node;

	if (!is_valid_number(s))
		return (0);
	result = ft_atol(s);
	if (result < -2147483648 || 2147483647 < result)
		return (0);
	node = ft_lstnew((int)result);
	if (!node)
		return (0);
	lst_add_back(stack, node);
	return (1);
}

t_num	*parse_args(int argc, char **argv)
{
	int		i;
	int		j;
	t_num	*stack;
	char	**temp;

	stack = NULL;
	i = 1;
	while(i < argc)
	{
		temp = ft_split(argv[i], ' ');
		// if (!temp)
		// 	return(free_stack(&stack), NULL)
		j = 0;
		while (temp[j])
		{
			if (!create_node(temp[j], &stack))
			{
				free_split(temp);
				free_stack(&stack);
				return (NULL);
			}
			j++;
		}
		free_split(temp);
		i++;
	}
	return (stack);
}




