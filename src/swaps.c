/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:36:51 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/20 11:47:55 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **x)
{
	t_list	*first;
	t_list	*second;

	if (!x || !(*x) || !(*x)->next)
		return ;
	first = (*x);
	second = (*x)->next;
	first->next = second->next;
	second->next = first;
	*x = second;
	init_values(x);
	return ;
}

void	swap_a(t_list **a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	swap_b(t_list **b)
{
	write(1, "sb\n", 3);
	swap(b);
}

void	swap_in_both_no_print(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}

void	swap_in_both(t_list **a, t_list **b)
{
	swap_in_both_no_print(a, b);
	write(1, "ss\n", 3);
}
