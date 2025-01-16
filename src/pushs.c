/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:51:16 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/16 11:29:49 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_dllist **a, t_dllist **b)
{
	t_dllist	*to_push;

	if (!b || !*b)
		return (1);
	to_push = *b;
	*b = to_push->next;
	to_push->next = NULL;
	to_push->prev = NULL;
	if (*a)
	{
		(*a)->prev = to_push;
		to_push->next = (*a);
		*a = to_push;
	}
	else
		*a = to_push;
	init_values(b);
	init_values(a);
	write(1, "pa\n", 3);
	return (0);
}

int	push_b(t_dllist **a, t_dllist **b)
{
	t_dllist	*to_push;

	if (!a || !*a)
		return (1);
	to_push = *a;
	*a = to_push->next;
	to_push->next = NULL;
	to_push->prev = NULL;
	if (*b)
	{
		(*b)->prev = to_push;
		to_push->next = (*b);
		*b = to_push;
	}
	else
		*b = to_push;
	init_values(b);
	init_values(a);
	write(1, "pb\n", 3);
	return (0);
}
