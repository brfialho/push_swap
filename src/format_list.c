/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:07:31 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/18 23:12:35 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	format_list(t_list **head)
{
	t_list	*dup;

	dup = lst_dup(*head, free);
	if (!dup)
		error_handler(head, NULL);
	lst_bubble_sort(dup, push_cmp_isgreater);
	if (check_for_repeats(&dup))
		error_handler(head, NULL);
	if (is_sorted(head, &dup))
		exit(0);
	assign_relative_value(dup);
	lst_del_all(&dup, NULL);
}
