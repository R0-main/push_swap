/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:09:19 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/14 10:16:47 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	process(t_dllist **a, t_dllist **b)
{
	// push all from a untile a == 3
	while (get_list_length(a) > 3)
		push_b(a, b);
	fast_sort(a);
}

int	main(int argc, char const *argv[])
{
	t_dllist	*a;
	t_dllist	*b;

	a = NULL;
	b = NULL;
	if (parse_arguments(&a, &b, argc, argv))
	{
		write(2, "ERROR WITH ARGS\n", 17);
		return (0);
	}
	if (!is_sorted(&a))
	{
		if (get_list_length(a) == 2)
			swap_a(&a);
		else if (get_list_length(a) == 3)
			fast_sort(&a);
		else
			process(a, b);
	}
	if (is_sorted(&a))
		printf("fqfwqfq\n\n");
	free_list(a);
	free_list(b);
	return (0);
}
