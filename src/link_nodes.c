/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:11:47 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/14 18:40:40 by rguigneb         ###   ########.fr       */
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
		// printf("current cost : %d\n", current->cost + current->target->cost);
		// printf("cheapest cost : %d\n", cheapest->cost + cheapest->target->cost);
		current = current->next;
	}
	return (cheapest);
}

t_dllist	*find_biggest(t_dllist **x)
{
	t_dllist	*current;
	t_dllist	*biggest;

	current = *x;
	while (current != NULL)
	{
		if (current == *x || current->value > biggest->value)
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

t_dllist	*get_target(t_dllist **to, t_dllist *k)
{
	if (k == find_biggest(to))
	{
		// printf("Small\n\n\n");
		return (find_smallest(to));
	}
	// printf("BIG\n\n\n");
	return (find_biggest(to));
}

void	link_nodes_from_b(t_dllist **a, t_dllist **b)
{
	int			i;
	t_dllist	*current;

	i = 0;
	current = *b;
	// init_values(a);
	while (current != NULL)
	{
		current->target = get_target(a, current);
		// printf("biggest value : %d\n", current->is_biggest);
		// printf("current value : %ld\n", current->value);
		// printf("target value : %ld\n", current->target->value);
		current = current->next;
	}
}
