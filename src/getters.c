/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:01:43 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/20 09:03:03 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cheapest(t_list **x)
{
	t_list	*current;
	t_list	*cheapest;

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

t_list	*find_biggest(t_list **x)
{
	t_list	*current;
	t_list	*biggest;

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

t_list	*find_smallest(t_list **x)
{
	t_list	*current;
	t_list	*smallest;

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

bool	exist_under(t_list **x, long lg)
{
	t_list	*current;

	current = *x;
	while (current)
	{
		if (current->value <= lg)
			return (true);
		current = current->next;
	}
	return (false);
}
