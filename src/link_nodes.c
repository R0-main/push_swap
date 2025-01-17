/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:11:47 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 14:04:54 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_target(t_list **to, t_list **from, t_list *k)
{
	t_list	*current;
	t_list	*to_biggest;
	t_list	*target;

	(void)from;
	current = *to;
	to_biggest = find_biggest(to);
	target = to_biggest;
	if (to_biggest && k->value >= to_biggest->value)
		return (find_smallest(to));
	while (current)
	{
		if ((current->value < target->value && current->value > k->value))
			target = current;
		current = current->next;
	}
	return (target);
}

void	link_nodes_from(t_list **to, t_list **from)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *from;
	while (current != NULL)
	{
		current->target = get_target(to, from, current);
		current = current->next;
	}
	init_values(to);
	init_values(from);
}
