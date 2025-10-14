/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_relative_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:06:01 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/13 20:43:03 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	assign_relative_value(t_list *lst, t_list *dup)
{
	t_list			*aux;
	unsigned long	len;

	len = 0;
	while (dup)
	{
		aux = lst_search(lst, dup->content, push_cmp_isequal);
		((t_number *)aux->content)->index = len++;
		dup = dup->next;
	}
}
