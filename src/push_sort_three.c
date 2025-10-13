/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:10:09 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/13 20:32:56 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	push_sort_three(t_stacks *stack)
{
	unsigned long first;
	unsigned long second;

	first = ((t_number *)((t_list *)*stack->a)->content)->index;
	second = ((t_number *)((t_list *)*stack->a)->next->content)->index;

	if (first == 1 && second == 0)
		sa(stack, TRUE);
	else if (first == 1 && second == 2)
		rra(stack, TRUE);
	else if (first == 2 && second == 0)
		ra(stack, TRUE);
	else if (first == 2 &&
			ra(stack, TRUE))
		sa(stack, TRUE);
	else if (\
		rra(stack, TRUE))
		sa(stack, TRUE);
}
