/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:57:10 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/08 15:51:18 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	ra(t_stacks *stack, int print)
{
	if (!*stack->a || !((t_list *)*stack->a)->next)
		return (FALSE);
	lst_add_end(stack->a, lst_detach(stack->a, *stack->a));
	if (print)
		write(1, "ra\n", 3);
	return (TRUE);
}
