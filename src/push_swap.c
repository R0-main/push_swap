/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:09:19 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 12:04:52 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

bool	get_under(t_dllist **x, long lg)
{
	t_dllist	*current;

	current = *x;
	while (current)
	{
		if (current->value <= lg)
			return (true);
		current = current->next;
	}
	return (false);
}

void	pre_ordered_push_to_b(t_dllist **a, t_dllist **b)
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
		if (!get_under(a, threshold))
			threshold += threshold_up;
		else if ((*a)->value <= threshold)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

void	process(t_dllist **a, t_dllist **b)
{
	t_dllist	*cheapest;
	t_dllist	*smallest;
	t_dllist	*biggest;

	cheapest = NULL;
	smallest = NULL;
	biggest = NULL;
	pre_ordered_push_to_b(a, b);
	fast_sort(a);
	while (*b)
	{
		init_values(a);
		init_values(b);
		link_nodes_from(a, b);
		cheapest = find_cheapest(b);
		if (!cheapest)
			break ;
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
		push_a(a, b);
	}
	biggest = find_biggest(a);
	while ((*a)->is_biggest == 0)
	{
		if (biggest->is_above_mediane)
			reverse_rotate_a(a);
		else
			rotate_a(a);
	}
	rotate_a(a);
}

int	main(int argc, char const **argv)
{
	t_dllist	*a;
	t_dllist	*b;

	a = NULL;
	b = NULL;
	if (parse_arguments(&a, &b, argc, argv))
	{
		write(2, "Error\n", 7);
		return (0);
	}
	if (!is_sorted(&a))
	{
		if (get_list_length(a) == 2)
			swap_a(&a);
		else if (get_list_length(a) == 3)
			fast_sort(&a);
		else
			process(&a, &b);
	}
	free_list(a);
	free_list(b);
	return (0);
}
