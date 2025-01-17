/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:36:51 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 12:01:26 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_dllist **x)
{
	t_dllist	*first;
	t_dllist	*second;

	if (!x || !(*x) || !(*x)->next)
		return (0);
	first = (*x);
	second = (*x)->next;
	first->next = second->next;
	second->next = first;
	*x = second;
	init_values(x);
	return (0);
}

int	swap_a(t_dllist **a)
{
	write(1, "sa\n", 3);
	return (swap(a));
}

int	swap_b(t_dllist **b)
{
	write(1, "sb\n", 3);
	return (swap(b));
}

int	swap_in_both(t_dllist **a, t_dllist **b)
{
	write(1, "ss\n", 3);
	return (swap_a(a) + swap_b(b));
}
