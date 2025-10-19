/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_loops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:09:09 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/19 01:15:04 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	calculate_loops(t_list *lst)
{
	int		bits;
	long	mask;
	long	max_number;

	bits = sizeof(long) * BYTE;
	mask = MASK;
	max_number = push_lst_size(lst) - 1;
	while (!(mask & max_number) && bits--)
		mask = mask >> 1;
	return (bits++);
}
