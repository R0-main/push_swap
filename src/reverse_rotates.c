/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:29:49 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/19 09:58:44 by rguigneb         ###   ########.fr       */
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
		if ((*x)->prev)
		{
			(*x)->prev->next = NULL;
			(*x)->prev = NULL;
		}
		(*x)->next = second;
	}
	if (second)
	{
		second->prev = last;
	}
	init_values(x);
	return (0);
}

int	reverse_rotate_a(t_dllist **a)
{
	write(1, "rra\n", 4);
	return (reverse_rotate(a));
}

int	reverse_rotate_b(t_dllist **b)
{
	write(1, "rrb\n", 4);
	return (reverse_rotate(b));
}

int	reverse_rotate_in_both(t_dllist **a, t_dllist **b)
{
	write(1, "rrr\n", 4);
	return (reverse_rotate_a(a) + reverse_rotate_b(b));
}
