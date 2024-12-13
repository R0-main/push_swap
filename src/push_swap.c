/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:09:19 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/13 15:36:54 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char const *argv[])
{
	t_dllist	*begin;
	t_dllist	*a;
	t_dllist	*b;

	// t_dllist	*lst;
	// t_dllist	*lst2;
	a = NULL;
	b = NULL;
	printf("%d\n", argc);
	if (parse_arguments(&a, &b, argc, argv))
	{
		write(2, "ERROR WITH ARGS\n", 17);
		return (0);
	}
	a = NULL;
	b = NULL;
	// lst = new_linked_list(15);
	// lst2 = new_linked_list(25);
	// printf("&a : %p\n", a);
	// add_back_of_list(&a, lst2);
	// add_back_of_list(&a, lst);
	// printf("&a : %p\n", a);
	printf("&a : %p\n", a);
	begin = a;
	while (begin)
	{
		printf("d : %d | prev : %p | next : %p\n", begin->value, begin->prev,
			begin->next);
		begin = begin->next;
	}
	printf("&a : %p\n", a);
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_a(&a, &b);
	push_a(&a, &b);
	swap_a(&a);
	swap_a(&a);
	swap_a(&a);
	swap_b(&b);
	rotate_b(&b);
	rotate_b(&b);
	rotate_b(&a);
	reverse_rotate_b(&b);
	reverse_rotate_b(&b);
	// rotate_a(&a);
	// swap_a(&a);
	// push_b(&a, &b);
	// push_b(&a, &b);
	printf("---------------b---------------\n");
	begin = b;
	while (begin)
	{
		printf("d : %d | prev : %p | next : %p\n", begin->value, begin->prev,
			begin->next);
		begin = begin->next;
	}
	printf("---------------a---------------\n");
	begin = a;
	while (begin)
	{
		printf("d : %d | prev : %p | next : %p\n", begin->value, begin->prev,
			begin->next);
		begin = begin->next;
	}
	free_list(a);
	free_list(b);
	// printf("d : %d | prev : %p | next : %p\n", a->next->value, a->next->prev,
	// a->next->next);
	return (0);
}
