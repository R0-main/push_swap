/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:52:21 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/19 09:53:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_list_length(t_dllist *first)
{
	int	i;

	i = 0;
	if (!first)
		return (0);
	while (first != NULL)
	{
		first = first->next;
		i++;
	}
	return (i);
}

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

t_dllist	*new_linked_list(long value)
{
	t_dllist	*lst;

	lst = (t_dllist *)malloc(sizeof(t_dllist));
	if (!lst)
		return (NULL);
	lst->value = value;
	lst->index = 0;
	lst->cost = 0;
	lst->is_biggest = 0;
	lst->target = NULL;
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

void	delete_element(t_dllist **element)
{
	(void)element;
	printf("prev : %p | next : %p\n", (*element)->prev, (*element)->next);
	if ((*element)->prev)
	{
		(*element)->prev->next = (*element)->next;
	}
	if ((*element)->next)
	{
		(*element) = (*element)->next;
		(*element)->next->prev = (*element);
	}
	// free(element);
}
