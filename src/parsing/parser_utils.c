/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:47:35 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/17 15:07:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_digit(int c)
{
	return (c <= '9' && c >= '0');
}

int	is_not_only_space_and_digits(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] > '9' || str[i] < '0') && str[i] != ' ' && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	is_not_only_digits(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' && !ft_is_digit(str[i + 1])) || (!ft_is_digit(str[i])
				&& str[i] != '-'))
			return (1);
		i++;
	}
	return (0);
}
