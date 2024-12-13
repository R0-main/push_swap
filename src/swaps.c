/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:36:51 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/13 12:05:36 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_dllist **a)
{
	t_dllist	*tmp;

	if (!(*a) || !(*a)->next)
		return (0);
	tmp = (*a)->next;
	tmp->prev = NULL;
	(*a)->next = tmp->next;
	tmp->next = *a;
	(*a)->prev = tmp;
	*a = tmp;
	return (0);
}
int	swap_b(t_dllist **b)
{
	t_dllist	*tmp;

	if (!(*b) || !(*b)->next)
		return (0);
	tmp = (*b)->next;
	(*b)->next = *b;
	*b = tmp;
	return (0);
}
