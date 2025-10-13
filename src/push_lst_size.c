/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lst_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:08:24 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/13 20:32:47 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

unsigned long	push_lst_size(t_list *head)
{
	long	size;

	size = 0;
	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}
