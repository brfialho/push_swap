/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:57:27 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/19 01:15:25 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	rb(t_stacks *stack, int print)
{
	if (!*stack->b || !((t_list *)*stack->b)->next)
		return (FALSE);
	lst_add_end(stack->b, lst_detach(stack->b, *stack->b));
	if (print)
		write(1, "rb\n", 3);
	return (TRUE);
}
