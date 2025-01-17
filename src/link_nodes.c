/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:11:47 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 12:00:55 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dllist	*find_cheapest(t_dllist **x)
{
	t_dllist	*current;
	t_dllist	*cheapest;

	current = *x;
	while (current != NULL)
	{
		if (current == *x || current->cost
			+ current->target->cost < cheapest->cost + cheapest->target->cost)
		{
			cheapest = current;
		}
		if (cheapest->cost + cheapest->target->cost == 0)
			return (cheapest);
		current = current->next;
	}
	return (cheapest);
}

t_dllist	*find_biggest(t_dllist **x)
{
	t_dllist	*current;
	t_dllist	*biggest;

	if (!x)
		return (NULL);
	current = *x;
	biggest = *x;
	while (current != NULL)
	{
		if (current->value > biggest->value)
		{
			biggest = current;
		}
		current = current->next;
	}
	return (biggest);
}

t_dllist	*find_smallest(t_dllist **x)
{
	t_dllist	*current;
	t_dllist	*smallest;

	current = *x;
	while (current != NULL)
	{
		if (current == *x || current->value < smallest->value)
		{
			smallest = current;
		}
		current = current->next;
	}
	return (smallest);
}

t_dllist	*get_target(t_dllist **to, t_dllist **from, t_dllist *k)
{
	t_dllist	*current;
	t_dllist	*to_biggest;
	t_dllist	*target;

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

void	link_nodes_from(t_dllist **to, t_dllist **from)
{
	int			i;
	t_dllist	*current;

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
