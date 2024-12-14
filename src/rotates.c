/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:29:49 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/14 15:29:49 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_dllist **x)
{
	t_dllist	*first;
	t_dllist	*last;

	if (!x || !*x)
		return (0);
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
	init_values(x);
	return (0);
}

int	rotate_a(t_dllist **a)
{
	write(1, "ra\n", 3);
	return (rotate(a));
}

int	rotate_b(t_dllist **b)
{
	write(1, "rb\n", 3);
	return (rotate(b));
}

int	rotate_in_both(t_dllist **a, t_dllist **b)
{
	write(1, "rr\n", 3);
	return (rotate_a(a) + rotate_b(b));
}
