/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:46:45 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/14 17:33:20 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calculate_mediane(t_dllist **a)
{
	size_t	mediane;
	int		lst_len;

	lst_len = get_list_length(*a);
	mediane = (lst_len / 2);
	if (lst_len > 2)
		mediane++;
	return (mediane);
}

void	calculate_and_apply_mediane(t_dllist **a)
{
	size_t		mediane;
	size_t		i;
	t_dllist	*current;

	mediane = calculate_mediane(a);
	i = mediane;
	current = *a;
	while (current != NULL)
	{
		if (current->index >= (int)mediane)
		{
			current->cost = i - 1;
			i--;
			current->is_above_mediane = 1;
		}
		else
		{
			current->cost = current->index;
			current->is_above_mediane = 0;
		}
		current = current->next;
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
	calculate_and_apply_mediane(a);
}
