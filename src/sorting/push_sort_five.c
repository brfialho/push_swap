/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:33:17 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/19 01:15:04 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	push_sort_five(t_stacks *stack)
{
	int	len;

	len = 5;
	while (len--)
	{
		if (*(long *)((t_list *)*stack->a)->content == 3
			|| *(long *)((t_list *)*stack->a)->content == 4)
			pb(stack);
		else
			ra(stack, TRUE);
	}
	push_sort_three(stack);
	if (*(long *)((t_list *)*stack->b)->content == 3)
		sb(stack, TRUE);
	pa(stack);
	pa(stack);
	ra(stack, TRUE);
	ra(stack, TRUE);
}
