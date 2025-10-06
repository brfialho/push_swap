/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:55:44 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/06 18:56:03 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	pa(t_stacks *stack)
{
	if (!*stack->b)
		return ;
	lst_add_start(stack->a, lst_detach(stack->b, *stack->b));
	write(1, "pa\n", 3);
}
