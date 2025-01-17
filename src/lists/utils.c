/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:52:21 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 13:38:26 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_list_length(t_list *first)
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

void	free_list(t_list *first)
{
	t_list	*tmp;

	while (first)
	{
		tmp = first->next;
		free(first);
		first = tmp;
	}
}

t_list	*new_linked_list(long value)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->value = value;
	lst->index = 0;
	lst->cost = 0;
	lst->target = NULL;
	lst->next = NULL;
	return (lst);
}

t_list	*get_last_element(t_list *first)
{
	if (!first)
		return (NULL);
	while (first->next != NULL)
		first = first->next;
	return (first);
}

t_list	*get_last_before_element(t_list *first)
{
	if (!first)
		return (NULL);
	if (get_list_length(first) == 2)
		return (first);
	if (get_list_length(first) == 3)
		return (first->next);
	while (first && first->next != NULL && first->next->next != NULL)
		first = first->next;
	return (first);
}
