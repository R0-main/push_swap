/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:09:19 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/14 18:48:39 by rguigneb         ###   ########.fr       */
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
			rotate_a(x);
		}
		else
		{
			rotate_b(x);
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

void	process(t_dllist **a, t_dllist **b)
{
	static int	i;
	t_dllist	*smallest;

	if (is_sorted(a))
		return ;
	// push all from a untile a == 3
	// while (get_list_length(*a) > 3)
	// 	push_b(a, b);
	// smallest = *b;
	// while (smallest)
	// {
	// 	printf("b : %ld", smallest->value);
	// 	smallest = smallest->next;
	// }
	// fast_sort(a);
	while (get_list_length(*a) > 3)
		push_b(a, b);
	fast_sort(a);
	while (*b)
	{
		init_values(a);
		init_values(b);
		link_nodes_from_b(a, b);
		execute_best_action(a, b);
	}
	smallest = find_smallest(a);
	if (smallest->is_above_mediane)
		while (*a != smallest)
			rotate_a(a);
	else
		while (*a != smallest)
			reverse_rotate_a(a);
	// process(a, b);
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
