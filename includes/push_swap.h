/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:12:15 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/08 09:19:54 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

typedef struct s_doubly_linked_list
{
	int						value;
	int						index;
	t_doubly_linked_list	*prev;
	t_doubly_linked_list	*next;
}							t_doubly_linked_list;

void	push_a(t_doubly_linked_list *a, t_doubly_linked_list *b);
void	push_b(t_doubly_linked_list *a, t_doubly_linked_list *b);

void	swap_a(t_doubly_linked_list *a, t_doubly_linked_list *b);
void	swap_b(t_doubly_linked_list *a, t_doubly_linked_list *b);

void	rotate_a(t_doubly_linked_list *a, t_doubly_linked_list *b);
void	rotate_b(t_doubly_linked_list *a, t_doubly_linked_list *b);

#endif
