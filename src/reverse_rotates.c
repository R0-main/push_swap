/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:29:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 13:53:40 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **x)
{
	t_list	*second;
	t_list	*before_last;
	t_list	*last;

	if (!x || !*x)
		return ;
	before_last = get_last_before_element(*x);
	last = before_last->next;
	before_last->next = NULL;
	second = *x;
	if (get_list_length(second) <= 1)
		return ;
	last->next = second;
	*x = last;
	init_values(x);
}

void	reverse_rotate_a(t_list **a)
{
	write(1, "rra\n", 4);
	reverse_rotate(a);
}

void	reverse_rotate_b(t_list **b)
{
	write(1, "rrb\n", 4);
	reverse_rotate(b);
}

void	reverse_rotate_in_both(t_list **a, t_list **b)
{
	write(1, "rrr\n", 4);
	reverse_rotate(a);
	reverse_rotate(b);
}
