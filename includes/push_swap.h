/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:12:15 by rguigneb          #+#    #+#             */
/*   Updated: 2024/12/12 16:20:28 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_doubly_linked_list
{
	int							value;
	int							index;
	struct s_doubly_linked_list	*prev;
	struct s_doubly_linked_list	*next;
}								t_dllist;
// t_doubly_linked_list;

// LST_UTILS
t_dllist						*new_linked_list(int value);

t_dllist						*get_last_element(t_dllist *first);
void							free_list(t_dllist *first);
void							add_front_of_list(t_dllist **first,
									t_dllist *to_add);
void							add_back_of_list(t_dllist **first,
									t_dllist *to_add);
int								parse_arguments(t_dllist **a, t_dllist **b,
									int argc, char const *argv[]);

void							push_a(t_dllist *a, t_dllist *b);
void							push_b(t_dllist *a, t_dllist *b);

void							swap_a(t_dllist *a, t_dllist *b);
void							swap_b(t_dllist *a, t_dllist *b);

void							rotate_a(t_dllist *a, t_dllist *b);
void							rotate_b(t_dllist *a, t_dllist *b);

void							reverse_rotate(t_dllist *a, t_dllist *b);
void							reverse_rotate_a(t_dllist *a, t_dllist *b);
void							reverse_rotate_b(t_dllist *a, t_dllist *b);
void							reverse_rotate_a_and_b(t_dllist *a,
									t_dllist *b);

// UTILS
size_t							ft_strlen(const char *s);
int								ft_atoi(const char *nptr);
int								is_not_only_digits(const char *str);
char							**ft_split(char const *s, char c);
void							free_split(char **tab, int index);
void							free_split_until_end(char **tab, int from);
char							*ft_substr(char const *s, unsigned int start,
									size_t len);

#endif
