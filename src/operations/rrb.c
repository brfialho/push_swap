/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:59:46 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/06 19:01:07 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	rrb(t_stacks *stack, int print)
{
	if (!*stack->b)
		return (FALSE);
	lst_add_start(stack->b, lst_detach(stack->b, lst_last(*stack->b)));
	if (print)
		write(1, "rrb\n", 4);
	return (TRUE);
}
