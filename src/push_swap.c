/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:09:19 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/20 09:03:09 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

static void	pre_ordered_push_to_b(t_list **a, t_list **b)
{
	long	threshold;
	long	threshold_up;

	if (get_list_length(*a) > 100)
		threshold_up = 85;
	else
		threshold_up = 62;
	threshold = threshold_up;
	while (get_list_length(*a) > 3)
	{
		if (!exist_under(a, threshold))
			threshold += threshold_up;
		else if ((*a)->value <= threshold)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

static void	align_at_the_same_time(t_list **a, t_list **b, t_list *cheapest)
{
	if (cheapest->is_above_mediane && cheapest->target->is_above_mediane)
	{
		while (1)
		{
			if (*b == cheapest || *a == cheapest->target)
				break ;
			reverse_rotate_in_both(a, b);
		}
	}
	else if (!cheapest->is_above_mediane && !cheapest->target->is_above_mediane)
	{
		while (1)
		{
			if (*b == cheapest || *a == cheapest->target)
				break ;
			rotate_in_both(a, b);
		}
	}
}

static bool	set_cheapest_and_target_at_top(t_list **a, t_list **b)
{
	t_list	*cheapest;

	cheapest = find_cheapest(b);
	if (!cheapest || !cheapest->target)
		return (false);
	align_at_the_same_time(a, b, cheapest);
	while (*b != cheapest)
	{
		if (cheapest->is_above_mediane)
			reverse_rotate_b(b);
		else
			rotate_b(b);
	}
	while (*a != cheapest->target)
	{
		if (cheapest->target->is_above_mediane)
			reverse_rotate_a(a);
		else
			rotate_a(a);
	}
	return (true);
}

static void	set_min_at_top(t_list **x)
{
	t_list	*biggest;

	biggest = find_biggest(x);
	while ((*x) != biggest)
	{
		if (biggest->is_above_mediane)
			reverse_rotate_a(x);
		else
			rotate_a(x);
	}
	rotate_a(x);
}

void	process(t_list **a, t_list **b)
{
	pre_ordered_push_to_b(a, b);
	fast_sort(a);
	while (*b)
	{
		init_values(a);
		init_values(b);
		link_nodes_from(a, b);
		if (!set_cheapest_and_target_at_top(a, b))
			break ;
		push_a(a, b);
	}
	set_min_at_top(a);
}
