/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast-sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:37:38 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 13:36:34 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fast_sort(t_list **x)
{
	t_list	*biggest;

	if (get_list_length(*x) < 3)
		return ;
	biggest = find_biggest(x);
	if ((*x) == biggest)
	{
		rotate_a(x);
		if ((*x)->value > (*x)->next->value)
			swap_a(x);
	}
	else if ((*x)->next == biggest)
	{
		reverse_rotate_a(x);
		if ((*x)->value > (*x)->next->value)
			swap_a(x);
	}
	else if ((*x)->next->next == biggest)
	{
		if ((*x)->value > (*x)->next->value)
			swap_a(x);
	}
}
