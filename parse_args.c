/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:07:20 by miandres          #+#    #+#             */
/*   Updated: 2026/02/01 10:37:38 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			return (0);
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

int	parse_argument(char	*str, t_num **stack)
{
	char	**temp;
	int		j;

	temp = ft_split(str, ' ');
	if (!temp || !temp[0])
	{
		free_split(temp);
		return (0);
	}
	j = 0;
	while (temp[j])
	{
		if (!create_node(temp[j], stack))
		{
			free_split(temp);
			return (0);
		}
		j++;
	}
	free_split(temp);
	return (1);
}

t_num	*parse_args(int argc, char **argv)
{
	int		i;
	t_num	*stack;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!parse_argument(argv[i], &stack))
		{
			free_stack(&stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}
