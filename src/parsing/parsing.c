/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:40:48 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 14:54:42 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	check_for_longer_than_int(t_list **a)
{
	t_list	*current;

	current = *a;
	while (current)
	{
		if (current->value > INT_MAX || current->value < INT_MIN)
			return (1);
		current = current->next;
	}
	return (0);
}

int	check_duplicates(t_list **a)
{
	t_list	*current;
	t_list	*current_begin;
	t_list	*beginning;

	beginning = *a;
	current = *a;
	while (current)
	{
		current_begin = beginning;
		while (current_begin)
		{
			if (current_begin->index != current->index
				&& current->value == current_begin->value)
				return (1);
			current_begin = current_begin->next;
		}
		current = current->next;
	}
	return (check_for_longer_than_int(a));
}

int	parse_multiple_args(t_list **a, t_list **b, int argc, char const **argv)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (++i < argc)
	{
		tmp = new_linked_list(ft_atoi(argv[i]));
		if (!tmp || is_not_only_digits(argv[i]))
			return (free_list(*a), free_list(*b), free_list(tmp), 1);
		add_back_of_list(a, tmp);
	}
	init_values(a);
	return (check_duplicates(a));
}

int	parse_one_string_args(t_list **a, t_list **b, char const **argv)
{
	int		i;
	t_list	*tmp;
	char	**strs;

	if (is_not_only_space_and_digits(argv[1]))
		return (1);
	i = 0;
	strs = ft_split((char *)argv[1], ' ');
	while (strs && strs[i])
	{
		tmp = new_linked_list(ft_atoi(strs[i]));
		if (!tmp || is_not_only_digits(strs[i]))
			return (free_list(*a), free_list(*b), free(tmp),
				free_split_until_end(strs, i), 1);
		free(strs[i]);
		add_back_of_list(a, tmp);
		i++;
	}
	free(strs);
	init_values(a);
	return (check_duplicates(a));
}

int	parse_arguments(t_list **a, t_list **b, int argc, char const **argv)
{
	if (argc <= 1)
		return (1);
	if (argc > 2)
		return (parse_multiple_args(a, b, argc, argv));
	else if (argc == 2)
		return (parse_one_string_args(a, b, argv));
	return (0);
}
