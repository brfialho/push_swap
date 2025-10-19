/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:53:24 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/19 01:15:04 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	error_handler(t_list **head, char **split)
{
	if (head)
	{
		lst_del_all(head, free);
		free(head);
	}
	if (split)
		ft_split_free(split);
	ft_printf("Error\n");
	exit(1);
}
