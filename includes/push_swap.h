/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:12:15 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/14 15:13:51 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_doubly_linked_list
{
	long						value;
	int							index;
	int							is_biggest;
	int							cost;
	int							is_above_mediane;
	struct s_doubly_linked_list	*target;
	struct s_doubly_linked_list	*prev;
	struct s_doubly_linked_list	*next;
}								t_dllist;
// t_doubly_linked_list;

// PARSING
int								parse_arguments(t_dllist **a, t_dllist **b,
									int argc, char const *argv[]);
void							init_values(t_dllist **a);

// FAST SORT
void							fast_sort(t_dllist **x);

// LST_UTILS
t_dllist						*new_linked_list(int value);
t_dllist						*get_last_element(t_dllist *first);
void							free_list(t_dllist *first);
void							delete_element(t_dllist **element);
void							add_front_of_list(t_dllist **first,
									t_dllist *to_add);
void							add_back_of_list(t_dllist **first,
									t_dllist *to_add);
int								get_list_length(t_dllist *first);

int								push_a(t_dllist **a, t_dllist **b);
int								push_b(t_dllist **a, t_dllist **b);

int								swap_a(t_dllist **a);
int								swap_b(t_dllist **b);

int								rotate_a(t_dllist **a);
int								rotate_b(t_dllist **b);
int								rotate_in_both(t_dllist **a, t_dllist **b);

// int								reverse_rotate(t_dllist **a, t_dllist **b);
int								reverse_rotate_a(t_dllist **a);
int								reverse_rotate_b(t_dllist **b);
int								reverse_rotate_in_both(t_dllist **a,
									t_dllist **b);

t_dllist						*find_cheapest(t_dllist **x);
int								is_sorted(t_dllist **x);
void							link_nodes_from_b(t_dllist **a, t_dllist **b);

// UTILS
size_t							ft_strlen(const char *s);
long							ft_atoi(const char *nptr);
int								is_not_only_digits(const char *str);
char							**ft_split(char const *s, char c);
void							free_split(char **tab, int index);
void							free_split_until_end(char **tab, int from);
char							*ft_substr(char const *s, unsigned int start,
									size_t len);

#endif
