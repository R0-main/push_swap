/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:46:45 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 12:00:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calculate_mediane(t_dllist **a)
{
	size_t	mediane;
	int		lst_len;

	lst_len = get_list_length(*a);
	mediane = (lst_len / 2);
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
		if (current->index > (int)mediane)
		{
			current->cost = i--;
			current->is_above_mediane = 1;
		}
		current = current->next;
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
