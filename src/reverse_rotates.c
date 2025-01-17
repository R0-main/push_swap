/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:29:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 09:28:58 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_dllist **x)
{
	t_dllist	*second;
	t_dllist	*before_last;
	t_dllist	*last;

	if (!x || !*x)
		return (0);
	before_last = get_last_before_element(*x);
	last = before_last->next;
	before_last->next = NULL;
	second = *x;
	if (get_list_length(second) <= 1)
		return (0);
	last->next = second;
	*x = last;
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
