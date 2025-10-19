/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:10:09 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/19 01:15:04 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	push_sort_three(t_stacks *stack)
{
	long	first;
	long	second;

	first = *(long *)((t_list *)*stack->a)->content;
	second = *(long *)((t_list *)*stack->a)->next->content;
	if (first == 1 && second == 0)
		sa(stack, TRUE);
	else if (first == 1 && second == 2)
		rra(stack, TRUE);
	else if (first == 2 && second == 0)
		ra(stack, TRUE);
	else if (first == 2 && second == 1
		&& ra(stack, TRUE))
		sa(stack, TRUE);
	else if (first == 0 && second == 2
		&& rra(stack, TRUE))
		sa(stack, TRUE);
}
