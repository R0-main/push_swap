/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:09:19 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/15 16:31:43 by rguigneb         ###   ########.fr       */
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
		printf("%ld | cost : %d | mediane : %d | index : %d\n", current->value,
			current->cost, current->is_above_mediane, current->index);
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
	t_dllist	*biggest;
	int			b_len;

	biggest = NULL;
	while (get_list_length(*a) > 0)
		push_b(a, b);
	while (*b)
	{
		init_values(b);
		init_values(a);
		b_len = get_list_length(*b);
		biggest = find_biggest(b);
		// printf("biggest : %ld\n", biggest->value);
		// print_list(b);
		while (*b != biggest)
		{
			// print_list(b);
			reverse_rotate_b(b);
		}
		// reverse_rotate_b(b);
		// if (biggest->index < b_len / 2)
		// 	while (*b != biggest)
		// 		reverse_rotate_b(b);
		// else
		// 	while (*b != biggest)
		// 		rotate_b(b);
		// printf("current : %ld\n", (*b)->value);
		// print_list(b);
		push_a(a, b);
		// push_a(a, b);
	}
	// push_a(a, b);
	// fast_sort(a);
	// // print_list_simple(a);
	// while (*b)
	// {
	// 	// print_list_simple(a);
	// 	link_nodes_from(a, b);
	// 	// calculate_and_apply_mediane_for_b(a, b);
	// 	// print_list(b);
	// 	execute_best_action(a, b);
	// 	// *b = (*b);
	// }
	// print_list(b);
	// smallest = find_smallest(a);
	// if (smallest->is_above_mediane)
	// 	while (*a != smallest)
	// 		rotate_a(a);
	// else
	// 	while (*a != smallest)
	// 		reverse_rotate_a(a);
	// t_dllist	*last;
	// t_dllist	*current;
	// t_dllist	*smallests;
	// t_dllist	*biggest;
	// smallests = NULL;
	// biggest = NULL;
	// current = *a;
	// last = get_last_element(*a);
	// while (current)
	// {
	// 	if (current->value > last->value)
	// 		add_back_of_list(&biggest, current);
	// 	else
	// 		add_back_of_list(&smallests, current);
	// 	current = current->next;
	// }
}

int	main(int argc, char const *argv[])
{
	t_dllist	*a;
	t_dllist	*b;
	t_dllist	*smallest;

	(void)smallest;
	a = NULL;
	b = NULL;
	if (parse_arguments(&a, &b, argc, argv))
	{
		write(2, "ERROR WITH ARGS\n", 17);
		return (0);
	}
	// smallest = a;
	// while (smallest)
	// {
	// 	printf("b : %ld\n", smallest->value);
	// 	smallest = smallest->next;
	// }
	if (!is_sorted(&a))
	{
		if (get_list_length(a) == 2)
			swap_a(&a);
		else if (get_list_length(a) == 3)
			fast_sort(&a);
		else
			process(&a, &b);
	}
	// printf("cost : %d\n", a->cost);
	// printf("cost : %d\n", a->next->cost);
	// printf("cost : %d\n", a->next->next->cost);
	// printf("cost : %d\n", a->next->next->next->cost);
	// if (is_sorted(&a))
	// 	printf("fqfwqfq\n\n");
	free_list(a);
	free_list(b);
	return (0);
}
