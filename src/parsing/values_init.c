/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:46:45 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/14 10:08:58 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_values(t_dllist **a)
{
	int		d;
	long		last_bigger;
	t_dllist	*bigger;
	t_dllist	*begin;

	d = 0;
	last_bigger = -1;
	bigger = NULL;
	begin = *a;
	while ((*a) != NULL)
	{
		if (d == 0 || (*a)->value > last_bigger)
		{
			last_bigger = (*a)->value;
			if (bigger)
				bigger->is_biggest = 0;
			bigger = (*a);
			(*a)->is_biggest = 1;
		}
		(*a)->index = ++d;
		(*a) = (*a)->next;
	}
	*a = begin;
}
