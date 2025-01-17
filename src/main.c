/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:00:09 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 15:10:20 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (parse_arguments(&a, &b, argc, argv))
	{
		write(2, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	if (!is_sorted(&a))
	{
		if (get_list_length(a) == 2)
			swap_a(&a);
		else if (get_list_length(a) == 3)
			fast_sort(&a);
		else
			process(&a, &b);
	}
	free_list(a);
	free_list(b);
	return (EXIT_SUCCESS);
}
