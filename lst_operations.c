/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandres <miandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:39:37 by miandres          #+#    #+#             */
/*   Updated: 2026/01/31 14:53:56 by miandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*ft_lstnew(int content)
{
	t_num	*node;

	node = malloc(sizeof(t_num));
	if (!node)
		return (NULL);
	node->rank = content;
	node->next = NULL;
	return (node);
}
void	lst_add_back(t_num **lst, t_num *new)
{
	t_num	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
