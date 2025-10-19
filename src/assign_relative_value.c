/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_relative_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:06:01 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/18 23:10:57 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	assign_relative_value(t_list *dup)
{
	unsigned long	len;

	len = 0;
	while (dup)
	{
		((t_number *)dup->content)->index = len++;
		dup = dup->next;
	}
}
