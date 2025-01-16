/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:46:45 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/16 12:21:59 by rguigneb         ###   ########.fr       */
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
	while (current != NULL && i < mediane - 1)
	{
		current->cost = i++;
		current->is_above_mediane = 1;
		current = current->prev;
	}
}

void	init_values(t_dllist **a)
{
	int			d;
	t_dllist	*biggest;
	t_dllist	*begin;

	d = 0;
	begin = *a;
	while (begin != NULL)
	{
		begin->index = d++;
		begin->cost = begin->index;
		begin->is_above_mediane = 0;
		begin->is_biggest = 0;
		begin = begin->next;
	}
	biggest = find_biggest(a);
	if (biggest)
		biggest->is_biggest = 1;
	if (*a)
		calculate_and_apply_mediane(a);
}
