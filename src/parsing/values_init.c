/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:46:45 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/15 15:19:55 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calculate_mediane(t_dllist **a)
{
	size_t	mediane;
	int		lst_len;

	lst_len = get_list_length(*a);
	mediane = (lst_len / 2);
	if (mediane == 1)
		mediane++;
	// printf("mediane : %zu\n", mediane);
	// if ((int)mediane < lst_len / 2)
	// 	mediane--;
	if ((lst_len / 2) % 2 != 0 && (lst_len / 2) != 1)
		mediane++;
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
	// printf("mediane : %zu\n", mediane);
	i = 0;
	current = *a;
	while (current != NULL)
	{
		if (current->index >= (int)mediane && mediane > 0)
		{
			if (current->index == len - 1)
				current->cost = 1;
			else
			{
				if (mediane - i - 1 > 1)
					current->cost = mediane - i - 1;
				else
					current->cost = 1;
			}
			current->is_above_mediane = 1;
			i++;
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
