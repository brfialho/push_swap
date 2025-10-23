/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:53:24 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/23 19:26:52 by brfialho         ###   ########.fr       */
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
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
