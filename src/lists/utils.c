/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:52:21 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/12 14:00:48 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_dllist *first)
{
	t_dllist	*tmp;

	while (first)
	{
		tmp = first->next;
		free(first);
		first = tmp;
	}
}

t_dllist	*new_linked_list(int value)
{
	t_dllist	*lst;

	lst = (t_dllist *)malloc(sizeof(t_dllist));
	if (!lst)
		return (NULL);
	lst->value = value;
	lst->index = 0;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

t_dllist	*get_last_element(t_dllist *first)
{
	if (!first)
		return (NULL);
	while (first->next != NULL)
		first = first->next;
	return (first);
}

void	add_front_of_list(t_dllist **first, t_dllist *to_add)
{
	if (!(*first))
	{
		*first = to_add;
		to_add->prev = NULL;
		to_add->next = NULL;
	}
	else
	{
		(*first)->prev = to_add;
		to_add->prev = NULL;
		to_add->next = *first;
		*first = to_add;
	}
}

void	add_back_of_list(t_dllist **first, t_dllist *to_add)
{
	t_dllist	*last;

	if (!*first)
	{
		*first = to_add;
		to_add->prev = NULL;
		to_add->next = NULL;
	}
	else
	{
		last = get_last_element(*first);
		last->next = to_add;
		to_add->prev = last;
	}
}
