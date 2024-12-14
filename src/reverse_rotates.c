/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:29:49 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/14 11:23:09 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_dllist **x)
{
	t_dllist	*second;
	t_dllist	*last;

	if (!x || !*x)
		return (0);
	last = get_last_element(*x);
	second = *x;
	if (get_list_length(second) == 1)
		return (0);
	*x = last;
	if (*x)
	{
		if (last->prev)
		{
			last->prev->next = NULL;
			last->prev = NULL;
		}
		last->next = second;
	}
	if (second)
	{
		second->prev = last;
		last = get_last_element(*x);
	}
	init_values(x);
	return (0);
}

int	reverse_rotate_a(t_dllist **a)
{
	return (reverse_rotate(a));
}

int	reverse_rotate_b(t_dllist **b)
{
	return (reverse_rotate(b));
}

int	reverse_rotate_in_both(t_dllist **a, t_dllist **b)
{
	return (reverse_rotate_a(a) + reverse_rotate_b(b));
}
