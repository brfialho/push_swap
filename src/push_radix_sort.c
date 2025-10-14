/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_radix_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:09:48 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/13 21:08:41 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	push_radix_sort(t_stacks *stack)
{
	int				loop;
	unsigned long	mask;
	unsigned long	i;
	unsigned long	len;

	len = push_lst_size(*stack->a);
	loop = calculate_loops(*stack->a);
	mask = 1;
	while (loop--)
	{
		i = 0;
		while (i++ < len)
		{
			if (!(((t_number *)((t_list *)*stack->a)->content)->index & mask))
				pb(stack);
			else
				ra(stack, TRUE);
		}
		while (i--)
			pa(stack);
		mask = mask << 1;
	}
}
