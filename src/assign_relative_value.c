/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_relative_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:06:01 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/19 00:03:05 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	assign_relative_value(t_list *dup)
{
	long	len;

	len = 0;
	while (dup)
	{
		*(long *)dup->content = len++;
		dup = dup->next;
	}
}
