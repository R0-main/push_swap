/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:51:16 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/12 17:20:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_dllist **a, t_dllist **b)
{
	add_front_of_list(a, *b);
	delete_element(b);
	(*a)->prev = NULL;
	(*a)->next = NULL;
}

void	push_b(t_dllist **a, t_dllist **b)
{
	add_front_of_list(b, *a);
	delete_element(a);
	(*b)->prev = NULL;
	(*b)->next = NULL;
}
