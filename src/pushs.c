/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:51:16 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/20 11:45:56 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*to_push;

	if (!b || !*b)
		return ;
	to_push = *b;
	*b = to_push->next;
	to_push->next = NULL;
	if (*a)
	{
		to_push->next = (*a);
		*a = to_push;
	}
	else
		*a = to_push;
	init_values(b);
	init_values(a);
}

void	push_a(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	push_b(t_list **a, t_list **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
