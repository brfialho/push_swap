/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:06:28 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/19 00:19:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	is_sorted(t_list **head, t_list **dup)
{
	t_list	*lst;
	t_list	*dup_lst;

	lst = *head;
	dup_lst = *dup;
	while (lst)
	{
		if (*(long *)lst->content != *(long *)dup_lst->content)
			return (FALSE);
		lst = lst->next;
		dup_lst = dup_lst->next;
	}
	lst_del_all(dup, NULL);
	lst_del_all(head, free);
	free(head);
	return (TRUE);
}
