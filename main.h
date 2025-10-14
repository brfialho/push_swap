/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:55:02 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/13 20:55:02 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft/headers/libft.h"

# ifndef MASK
#  define MASK 9223372036854775808UL
# endif

typedef struct s_number
{
	long			number;
	unsigned long	index;
}	t_number;

typedef struct s_stacks
{
	t_list	**a;
	t_list	**b;
}	t_stacks;

// Operations

void	pa(t_stacks *stack);
void	pb(t_stacks *stack);
int		ra(t_stacks *stack, int print);
int		rb(t_stacks *stack, int print);
void	rr(t_stacks *stack);
int		rra(t_stacks *stack, int print);
int		rrb(t_stacks *stack, int print);
void	rrr(t_stacks *stack);
int		sa(t_stacks *stack, int print);
int		sb(t_stacks *stack, int print);
void	ss(t_stacks *stack);

// Functions

int		append_node(char *input, t_list **head);
void	assign_relative_value(t_list *lst, t_list *dup);
int		calculate_loops(t_list *lst);
int		check_for_repeats(t_list **dup);
void	error_handler(t_list **head, char **split);
void	format_list(t_list **head);
t_list	**get_list(int argc, char *argv[]);
void	init_stack_b(t_stacks *stack);
int		is_sorted(t_list **head, t_list **dup);
long	push_atol(char *s);
int		push_cmp_isequal(void *i, void *j);
int		push_cmp_isgreater(void *i, void *j);
void	*push_copy_content(void	*content);
long	push_lst_size(t_list *head);
void	push_radix_sort(t_stacks *stack);
void	push_sort_three(t_stacks *stack);
void	split_input(char *s, t_list **head);

#endif