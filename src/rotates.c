/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:29:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 13:27:40 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_list **x)
{
	t_list	*first;
	t_list	*last;

	if (!x || !*x)
		return (0);
	first = *x;
	if (get_list_length(first) <= 1)
		return (0);
	last = get_last_element(*x);
	*x = (*x)->next;
	first->next = NULL;
	last->next = first;
	init_values(x);
	return (0);
}

int	rotate_a(t_list **a)
{
	write(1, "ra\n", 3);
	return (rotate(a));
}

int	rotate_b(t_list **b)
{
	write(1, "rb\n", 3);
	return (rotate(b));
}

int	rotate_in_both(t_list **a, t_list **b)
{
	write(1, "rr\n", 3);
	return (rotate_a(a) + rotate_b(b));
}
