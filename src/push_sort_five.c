/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:33:17 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/13 22:02:37 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	push_sort_five(t_stacks *stack)
{
	int	len;

	len = 5;
	while (len--)
	{
		if (((t_number *)((t_list *)*stack->a)->content)->index == 3
			|| ((t_number *)((t_list *)*stack->a)->content)->index == 4)
			pb(stack);
		else
			ra(stack, TRUE);
	}
	push_sort_three(stack);
	if (((t_number *)((t_list *)*stack->b)->content)->index == 3)
		sb(stack, TRUE);
	pa(stack);
	pa(stack);
	ra(stack, TRUE);
	ra(stack, TRUE);
}
