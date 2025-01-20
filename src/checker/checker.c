/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:13:57 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/20 08:51:33 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

bool	do_move(t_list **a, t_list **b, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		push_a(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		push_b(a, b);
	else if (ft_strcmp(line, "sa\n") == 0)
		swap_a(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_b(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_in_both(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate_a(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate_b(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_in_both(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate_a(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate_b(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		reverse_rotate_in_both(a, b);
	else
		return (false);
	return (true);
}

void	free_lists(t_list **a, t_list **b)
{
	free_list(*a);
	free_list(*b);
	*a = NULL;
	*b = NULL;
}

void	read_moves(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!do_move(a, b, line))
		{
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(0);
	}
}

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
	read_moves(&a, &b);
	if (is_sorted(&a) && get_list_length(b) == 0)
	{
		write(1, "OK\n", 4);
		return (free_lists(&a, &b), EXIT_SUCCESS);
	}
	else
	{
		write(2, "KO\n", 4);
		return (free_lists(&a, &b), EXIT_FAILURE);
	}
}
