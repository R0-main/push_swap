/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:12:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/20 11:50:12 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_linked_list
{
	long					value;
	int						index;
	int						cost;
	int						is_above_mediane;
	struct s_linked_list	*target;
	struct s_linked_list	*next;
}							t_list;

/****************************parsing*******************************************/
int							parse_arguments(t_list **a, t_list **b, int argc,
								char const **argv);
bool						ft_is_digit(int c);

int							is_not_only_space_and_digits(const char *str);
int							is_not_only_digits(const char *str);

/****************************fast-sort*****************************************/
t_list						*get_last_before_element(t_list *first);
void						fast_sort(t_list **x);

/****************************lists-utils***************************************/
t_list						*new_linked_list(long value);
t_list						*get_last_element(t_list *first);
void						free_list(t_list *first);
void						add_front_of_list(t_list **first, t_list *to_add);
void						add_back_of_list(t_list **first, t_list *to_add);
int							get_list_length(t_list *first);

/****************************moves*********************************************/
void						push(t_list **a, t_list **b);
void						push_a(t_list **a, t_list **b);
void						push_b(t_list **a, t_list **b);
void						swap(t_list **x);
void						swap_a(t_list **a);
void						swap_b(t_list **b);
void						swap_in_both(t_list **a, t_list **b);
void						swap_in_both_no_print(t_list **a, t_list **b);
void						rotate_in_both_no_print(t_list **a, t_list **b);
void						rotate(t_list **x);
void						rotate_a(t_list **a);
void						rotate_b(t_list **b);
void						reverse_rotate(t_list **x);
void						rotate_in_both(t_list **a, t_list **b);
void						reverse_rotate_a(t_list **a);
void						reverse_rotate_b(t_list **b);
void						reverse_rotate_in_both(t_list **a, t_list **b);
void						reverse_rotate_in_both_no_print(t_list **a,
								t_list **b);

/****************************getters*******************************************/
t_list						*find_cheapest(t_list **x);
t_list						*find_smallest(t_list **x);
t_list						*find_biggest(t_list **x);

/****************************algo-utils****************************************/
bool						is_sorted(t_list **x);
bool						exist_under(t_list **x, long lg);
void						init_values(t_list **a);

/****************************utils*********************************************/
size_t						ft_strlen(const char *s);
long						ft_atoi(const char *nptr);
int							is_not_only_digits(const char *str);
char						**ft_split(char const *s, char c);
void						free_split(char **tab, int index);
void						free_split_until_end(char **tab, int from);
char						*ft_substr(char const *s, unsigned int start,
								size_t len);
t_list						*find_cheapest(t_list **x);
t_list						*find_biggest(t_list **x);
t_list						*find_smallest(t_list **x);
bool						exist_under(t_list **x, long lg);
void						link_nodes_from(t_list **to, t_list **from);
void						process(t_list **a, t_list **b);

/****************************bonus*********************************************/
typedef enum e_moves
{
	PB,
	PA,
	SA,
	SB,
	RA,
	RB,
	RRA,
	RRB,
	RRR,
	RR,
	SS,
	LAST_MOVE
}							t_moves;

#endif
