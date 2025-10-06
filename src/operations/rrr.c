/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:00:07 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/06 19:00:13 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	rrr(t_stacks *stack)
{
	int	print;

	print = 0;
	print += rra(stack, FALSE);
	print += rrb(stack, FALSE);
	if (print)
		write(1, "rrr\n", 4);
}
