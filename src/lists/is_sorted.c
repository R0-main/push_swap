/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:10:21 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 13:27:40 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **x)
{
	long	last_n;
	int		first_loop;
	t_list	*current;

	last_n = 0;
	first_loop = 1;
	current = *x;
	while (current != NULL)
	{
		if (first_loop == 0 && current->value < last_n)
			return (0);
		if (first_loop == 1)
			first_loop = 0;
		last_n = current->value;
		current = current->next;
	}
	return (1);
}
