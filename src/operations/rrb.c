/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:59:46 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/19 01:15:25 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	rrb(t_stacks *stack, int print)
{
	if (!*stack->b || !((t_list *)*stack->b)->next)
		return (FALSE);
	lst_add_start(stack->b, lst_detach(stack->b, lst_last(*stack->b)));
	if (print)
		write(1, "rrb\n", 4);
	return (TRUE);
}
