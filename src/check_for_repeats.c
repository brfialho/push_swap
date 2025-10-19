/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_repeats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:05:35 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/19 00:22:52 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	check_for_repeats(t_list **dup)
{
	t_list	*tmp;

	tmp = *dup;
	while (tmp && tmp->next)
	{
		if (*(long *)tmp->content == *(long *)tmp->next->content)
			return (lst_del_all(dup, NULL), 1);
		tmp = tmp->next;
	}
	return (0);
}
