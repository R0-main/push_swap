/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_only_digits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:47:35 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/12 14:48:51 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_only_digits(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (1);
		i++;
	}
	return (0);
}
