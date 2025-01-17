/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast-sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:37:38 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 10:37:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fast_sort(t_dllist **x)
{
	if (get_list_length(*x) < 3)
		return ;
	if ((*x)->is_biggest)
	{
		rotate_a(x);
		if ((*x)->value > (*x)->next->value)
			swap_a(x);
	}
	else if ((*x)->next->is_biggest)
	{
		reverse_rotate_a(x);
		if ((*x)->value > (*x)->next->value)
			swap_a(x);
	}
	else if ((*x)->next->next->is_biggest)
	{
		if ((*x)->value > (*x)->next->value)
			swap_a(x);
	}
}
