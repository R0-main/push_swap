/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:29:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/20 11:48:48 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **x)
{
	t_list	*first;
	t_list	*last;

	if (!x || !*x)
		return ;
	first = *x;
	if (get_list_length(first) <= 1)
		return ;
	last = get_last_element(*x);
	*x = (*x)->next;
	first->next = NULL;
	last->next = first;
	init_values(x);
}

void	rotate_a(t_list **a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

void	rotate_b(t_list **b)
{
	write(1, "rb\n", 3);
	rotate(b);
}

void	rotate_in_both_no_print(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}

void	rotate_in_both(t_list **a, t_list **b)
{
	rotate_in_both_no_print(a, b);
	write(1, "rr\n", 3);
}
