/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:54:42 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/06 18:55:05 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	ss(t_stacks *stack)
{
	int	print;

	print = 0;
	print += sa(stack, FALSE);
	print += sb(stack, FALSE);
	if (print)
		write(1, "ss\n", 3);
}
