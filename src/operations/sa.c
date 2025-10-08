/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:51:51 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/08 15:53:12 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	sa(t_stacks *stack, int print)
{
	if (!*stack->a || !((t_list *)*stack->a)->next)
		return (FALSE);
	lst_add_start(stack->a, lst_detach(stack->a, (*stack->a)->next));
	if (print)
		write(1, "sa\n", 3);
	return (TRUE);
}
