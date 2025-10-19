/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:55:02 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/19 01:14:21 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft/headers/libft.h"

// Macro for Radix logic

# ifndef MASK
#  define MASK 9223372036854775808UL
# endif

// Structs
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

t_list	**get_list(int argc, char *argv[]);

void	assign_relative_value(t_list *dup);
void	error_handler(t_list **head, char **split);
void	format_list(t_list **head);
void	init_stack_b(t_stacks *stack);
void	push_radix_sort(t_stacks *stack);
void	push_sort_three(t_stacks *stack);
void	push_sort_five(t_stacks *stack);
void	split_input(char *s, t_list **head);

int		push_cmp_isgreater(void *i, void *j);
int		append_node(char *input, t_list **head);
int		calculate_loops(t_list *lst);
int		check_for_repeats(t_list **dup);
int		is_sorted(t_list **head, t_list **dup);
int		push_cmp_isequal(void *i, void *j);

long	push_atol(char *s);
long	push_lst_size(t_list *head);

#endif