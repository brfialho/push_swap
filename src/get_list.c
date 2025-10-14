/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:03:16 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/13 22:08:13 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_list	**get_list(int argc, char *argv[])
{
	t_list	**head;
	long	i;

	if (argc < 2)
		exit(1);
	head = ft_calloc(1, sizeof(t_list **));
	if (!head)
		error_handler(NULL, NULL);
	i = 1;
	while (i < argc)
		split_input(argv[i++], head);
	return (head);
}
