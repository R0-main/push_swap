/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:09:19 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/16 15:29:33 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	finish_rotation(t_dllist **x, t_dllist *cheapest, int type)
{
	while (*x != cheapest)
	{
		if (type == 'a')
		{
			if (!cheapest->is_above_mediane)
				rotate_a(x);
			else
				reverse_rotate_a(x);
		}
		else
		{
			if (!cheapest->is_above_mediane)
				rotate_b(x);
			else
				reverse_rotate_b(x);
		}
	}
}

void	execute_best_action(t_dllist **a, t_dllist **b)
{
	t_dllist	*cheapest;

	cheapest = find_cheapest(b);
	if (cheapest->is_above_mediane && cheapest->target->is_above_mediane)
	{
		while (*a != cheapest->target && *b != cheapest)
			rotate_in_both(a, b);
	}
	else if (!(cheapest->is_above_mediane
			&& cheapest->target->is_above_mediane))
	{
		while (*a != cheapest->target && *b != cheapest)
			reverse_rotate_in_both(a, b);
	}
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target, 'a');
	// printf("cheapest : %ld\n", cheapest->value);
	push_a(a, b);
}

void	combine(t_dllist *smallests, t_dllist *biggest, t_dllist *pivot)
{
	t_dllist	*current;

	current = get_last_element(smallests);
	if (current)
		current->next = pivot;
	if (pivot)
	{
		pivot->prev = current;
		pivot->next = biggest;
	}
	if (biggest)
		biggest->prev = pivot;
}

t_dllist	*quick_sort(t_dllist **x)
{
	t_dllist	*last;
	t_dllist	*current;
	t_dllist	*smallests;
	t_dllist	*biggest;

	// printf("length : %d\n", get_list_length(*x));
	if (get_list_length(*x) <= 1)
		return (*x);
	if (get_list_length(*x) == 3)
	{
		fast_sort(x);
		return (*x);
	}
	smallests = NULL;
	biggest = NULL;
	last = get_last_element(*x);
	current = *x;
	while (current->next != NULL)
	{
		if (current->value > last->value)
			add_back_of_list(&biggest, new_linked_list(current->value));
		else
			add_front_of_list(&smallests, new_linked_list(current->value));
		// printf("smallests v : %ld\n", smallests->value);
		current = current->next;
		// printf("biggest v : %p\n", current->next);
	}
	if (get_list_length(smallests) > 1)
		smallests = quick_sort(&smallests);
	if (get_list_length(biggest) > 1)
		biggest = quick_sort(&biggest);
	combine(smallests, biggest, last);
	return (smallests);
}
void	print_list_simple(t_dllist **x)
{
	t_dllist	*current;

	current = *x;
	while (current)
	{
		printf("%ld | cost : %d | is above mediane : %d | index : %d\n",
			current->value, current->cost, current->is_above_mediane,
			current->index);
		current = current->next;
	}
}

void	print_list(t_dllist **x)
{
	t_dllist	*current;

	current = *x;
	printf("List : \n");
	while (current)
	{
		printf("%ld |  index : %d\n", current->value, current->index);
		current = current->next;
	}
}

void	process(t_dllist **a, t_dllist **b)
{
	t_dllist	*cheapest;
	t_dllist	*smallest;
	t_dllist	*biggest;
	int			d;

	cheapest = NULL;
	smallest = NULL;
	biggest = NULL;
	while (get_list_length(*a) > 3)
		push_b(a, b);
	fast_sort(a);
	while (*b)
	{
		// printf("HERE : %ld\n", (*b)->next->value);
		// printf("------------------");
		// print_list(b);
		// printf("------------------");
		init_values(a);
		init_values(b);
		link_nodes_from(a, b);
		cheapest = find_cheapest(b);
		if (!cheapest)
			break ;
		// print_list_simple(b);
		// printf("cheapest : %ld | cost : %d\n", cheapest->value,
		// cheapest->cost);
		// while (*b != cheapest && *a != cheapest->target)
		// {
		// 	if (cheapest->is_above_mediane)
		// 		reverse_rotate_in_both(a, b);
		// 	else
		// 		rotate_in_both(a, b);
		// }
		d = (int)calculate_mediane(b);
		while (*b != cheapest)
		{
			if (cheapest->index > d)
				reverse_rotate_b(b);
			else
				rotate_b(b);
		}
		// int c = (int)calculate_mediane(a);
		while (*a != cheapest->target)
		{
			// printf("a\n");
			// printf("target : %ld\n", cheapest->target->value);
			// printf("current a : %ld\n", (*a)->value);
			// if (cheapest->target->index > get_list_length(*a) / 2)
			reverse_rotate_a(a);
			// else
				// rotate_a(a);
			// }
		}
		push_a(a, b);
	}
	// init_values(a);
	// init_values(b);
	// link_nodes_from(a, b);
	biggest = find_biggest(a);
	// biggest = find_biggest(a);
	// printf("smallest cost : %d\n", smallest->cost);
	// printf("biggest cost: %d\n", biggest->cost);
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
