/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:51:16 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/13 09:20:43 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_dllist **a, t_dllist **b)
{
	t_dllist	*next;

	if (!b || !*b)
		return (1);
	if (*a == NULL)
	{
		next = (*b)->next;
		(*b)->next = NULL;
		next->prev = NULL;
		*a = *b;
		*b = next;
	}
	else
	{
		next = (*b)->next;
		next->prev = NULL;
		(*b)->next = (*a);
		(*a)->prev = *b;
		*a = (*a)->prev;
		*b = next;
	}
	return (0);
}

int	push_b(t_dllist **a, t_dllist **b)
{
	t_dllist	*next;

	if (!a || !*a)
		return (1);
	if (*b == NULL)
	{
		next = (*a)->next;
		(*a)->next = NULL;
		next->prev = NULL;
		*b = *a;
		*a = next;
	}
	else
	{
		next = (*a)->next;
		next->prev = NULL;
		(*a)->next = (*b);
		(*b)->prev = *a;
		*b = (*b)->prev;
		*a = next;
	}
	return (0);
}
