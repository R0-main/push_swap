/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:46:45 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/19 10:03:56 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calculate_mediane(t_dllist **a)
{
	size_t	mediane;
	int		lst_len;

	lst_len = get_list_length(*a);
	mediane = (lst_len / 2);
	// if (lst_len % 2 != 0)
	// 	mediane++;
	// if (mediane == 1)
	// 	mediane++;
	// // printf("mediane : %zu\n", mediane);
	// if ((int)mediane < lst_len / 2)
	// 	mediane--;
	// if ((lst_len / 2) % 2 != 0 && (lst_len / 2) != 1)
	// 	mediane++;
	return (mediane);
}

void	calculate_and_apply_mediane(t_dllist **a)
{
	size_t		mediane;
	size_t		i;
	t_dllist	*current;
	int			len;

	mediane = calculate_mediane(a);
	len = get_list_length(*a);
	// print_list(a);
	// printf("mediane : %zu\n", mediane);
	i = 1;
	current = get_last_element(*a);
	while (current != NULL && i <= mediane)
	{
		current->cost = i++;
		current->is_above_mediane = 1;
		current = current->prev;
	}
	while (current != NULL) // FIX !+ NULL
	{
		// printf("current : %p | prev : %p\n", current, current->prev);
		current->is_above_mediane = 0;
		current->cost = current->index;
		current = current->prev;
	}
}

void	init_values(t_dllist **a)
{
	int			d;
	long		last_bigger;
	t_dllist	*bigger;
	t_dllist	*begin;

	d = 0;
	last_bigger = -1;
	bigger = *a;
	begin = *a;
	while (begin != NULL)
	{
		if (d == 0 || begin->value > last_bigger)
		{
			last_bigger = begin->value;
			bigger->is_biggest = 0;
			bigger = begin;
			begin->is_biggest = 1;
		}
		begin->index = d++;
		begin = begin->next;
	}
	// find_biggest(a)->is_biggest = 1;
	calculate_and_apply_mediane(a);
}
