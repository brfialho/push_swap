/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:57:46 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/06 18:57:55 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	rr(t_stacks *stack)
{
	int	print;

	print = 0;
	print += ra(stack, FALSE);
	print += rb(stack, FALSE);
	if (print)
		write(1, "rr\n", 3);
}
