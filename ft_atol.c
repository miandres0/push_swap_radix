/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:17:40 by miandres          #+#    #+#             */
/*   Updated: 2026/02/01 01:18:47 by miandres         ###   ########.fr       */
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
