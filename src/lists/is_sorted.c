/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:10:21 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 14:09:35 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list **x)
{
	long	last_n;
	t_list	*current;

	if (!*x)
		return (true);
	current = *x;
	last_n = current->value;
	while (current != NULL)
	{
		if (current->value < last_n)
			return (false);
		last_n = current->value;
		current = current->next;
	}
	return (1);
}
