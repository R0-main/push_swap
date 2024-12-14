/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:09:19 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/14 15:27:30 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	execute_best_action(t_dllist **a, t_dllist **b)
{
	t_dllist	*cheapest;

	cheapest = find_cheapest(b);
	if (cheapest->is_above_mediane && cheapest->target->is_above_mediane)
	{
		reverse_rotate_in_both(a, b);
	}
	// printf("cheapest : %ld\n", cheapest->value);
}

void	process(t_dllist **a, t_dllist **b)
{
	// push all from a untile a == 3
	while (get_list_length(*a) > 3)
		push_b(a, b);
	fast_sort(a);
	init_values(b);
	link_nodes_from_b(a, b);
	execute_best_action(a, b);
}

int	main(int argc, char const *argv[])
{
	t_dllist	*a;
	t_dllist	*b;

	a = NULL;
	b = NULL;
	if (parse_arguments(&a, &b, argc, argv))
	{
		write(2, "ERROR WITH ARGS\n", 17);
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
	// printf("cost : %d\n", a->cost);
	// printf("cost : %d\n", a->next->cost);
	// printf("cost : %d\n", a->next->next->cost);
	// printf("cost : %d\n", a->next->next->next->cost);
	if (is_sorted(&a))
		printf("fqfwqfq\n\n");
	free_list(a);
	free_list(b);
	return (0);
}
