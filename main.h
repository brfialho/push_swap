/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:55:02 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/06 19:04:06 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft/headers/libft.h"

struct s_number {
	long	number;
	long	index;
} typedef t_number;

struct s_stacks {
	t_list	**a;
	t_list	**b;
} typedef t_stacks;

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

#endif