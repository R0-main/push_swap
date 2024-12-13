/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:36:51 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/13 15:11:22 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int swap(t_dllist **x)
{
	t_dllist	*tmp;

	if (!(*x) || !(*x)->next)
		return (0);
	tmp = (*x)->next;
	tmp->prev = NULL;
	(*x)->next = tmp->next;
	tmp->next = *x;
	(*x)->prev = tmp;
	*x = tmp;
	return (0);
}

int	swap_a(t_dllist **a)
{
	return (swap(a));
}
int	swap_b(t_dllist **b)
{
	return (swap(b));
}

int	swap_in_both(t_dllist **a, t_dllist **b)
{
	swap_a(a);
	swap_b(b);
}
