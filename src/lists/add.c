/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:54:47 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 09:17:01 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front_of_list(t_dllist **first, t_dllist *to_add)
{
	if (!(*first))
	{
		*first = to_add;
		to_add->next = NULL;
	}
	else
	{
		to_add->next = *first;
		*first = to_add;
	}
}

void	add_back_of_list(t_dllist **first, t_dllist *to_add)
{
	t_dllist	*last;

	if (!*first)
		*first = to_add;
	else
	{
		last = get_last_element(*first);
		last->next = to_add;
	}
	to_add->next = NULL;
}
