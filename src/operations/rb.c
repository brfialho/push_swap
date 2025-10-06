/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:57:27 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/06 18:57:36 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	rb(t_stacks *stack, int print)
{
	if (!*stack->b)
		return (FALSE);
	lst_add_end(stack->b, lst_detach(stack->b, *stack->b));
	if (print)
		write(1, "rb\n", 3);
	return (TRUE);
}
