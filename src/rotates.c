/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:29:49 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/13 15:05:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int rotate(t_dllist **x)
{
	t_dllist	*first;
	t_dllist	*last;

	first = *x;
	if (get_list_length(first) == 1)
		return (0);
	last = get_last_element(*x);
	*x = (*x)->next;
	if (*x)
		(*x)->prev = NULL;
	if (first)
	{
		first->next = NULL;
		first->prev = last;
	}
	if (last)
		last->next = first;
	return (0);
}

int	rotate_a(t_dllist **a)
{
	return (rotate(a));
}

int	rotate_b(t_dllist **b)
{
	return (rotate(b));
}
