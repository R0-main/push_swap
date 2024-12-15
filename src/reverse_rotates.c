/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:29:49 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/15 16:25:32 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_dllist **x)
{
	t_dllist	*last; //To store the pointer to the last node

	if (!*x || !(*x)->next) //Check if the stack is empty, or if there's one node
		return (0);
	last = get_last_element(*x);
	last->prev->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
	last->next = *x; //Assign to its own `next` attribute as the top node of the stack
	last->prev = NULL; //Detach itself from the node before it
	*x = last;  //Complete appending itself to the top of the stack, and now holds the pointer to the top node
	last->next->prev = last; //Update the current last node of the stack
	init_values(x);
	return (0);
}

int	reverse_rotate_a(t_dllist **a)
{
	write(1, "rra\n", 5);
	return (reverse_rotate(a));
}

int	reverse_rotate_b(t_dllist **b)
{
	write(1, "rrb\n", 5);
	return (reverse_rotate(b));
}

int	reverse_rotate_in_both(t_dllist **a, t_dllist **b)
{
	write(1, "rrr\n", 5);
	return (reverse_rotate_a(a) + reverse_rotate_b(b));
}
