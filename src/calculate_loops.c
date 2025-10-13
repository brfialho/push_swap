/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_loops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:09:09 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/13 20:33:27 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	calculate_loops(t_list *lst)
{
	int				bits;
	unsigned long	mask;
	unsigned long	max_index;

	bits = sizeof(unsigned long) * BYTE;
	mask = MASK;
	max_index = push_lst_size(lst) - 1;
	while (!(mask & max_index) && bits--)
		mask = mask >> 1;
	return (bits++);
}
