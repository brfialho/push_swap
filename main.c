/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:53:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/26 22:17:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	error_handler(t_list **head, char **split)
{
	if (head)
	{
		if (*head)
			ft_lstclear(head, free);
		free(head);
	}
	if (split)
		ft_split_free(split);
	ft_printf("Error\n");
	exit(1);
}

long	push_atol(char *s)
{
	long	sum;
	int		sign;

	sign = 1;
	sum = 0;
	if (*s == '+' || *s == '-')
	{		
		if (*s == '-' && s++)
			sign = -1;
		else
			s++;
	}
	while (*s)
	{
		if (!ft_isdigit(*s))
			return ((long)INT_MAX + INT_MAX);
		sum = sum * 10 + *s++ - '0';
		if ((sum > (long)INT_MAX + 1 && sign < 0) ||
			(sum > (long)INT_MAX && sign > 0))
			return ((long)INT_MAX + INT_MAX);
	}
	return (sum * sign);
}

int	append_node(char *input, t_list **head)
{
	t_list	*new;
	long	*n;

	n = ft_calloc(1, sizeof(long));
	if (!n)
		return (0);
	*n = push_atol(input);
	if (*n > INT_MAX)
		return (free(n), 0);
	new = ft_lstnew(n);
	if (!new)
		return (free(n), 0);
	if (!*head)
		*head = new;
	else
		ft_lstadd_back(head, new);
	return (1);
}
void	split_input(char *s, t_list **head)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(s, ' ');
	if (!split)
		error_handler(head, NULL);
	while (split[i])
		if(!append_node(split[i++], head))
			error_handler(head, split);
	ft_split_free(split);
}


t_list	*get_list(int argc, char* argv[])
{
	t_list	**head;
	t_list	*list;
	int		i;

	if (argc < 2)
		error_handler(NULL, NULL);
	i = 1;
	head = ft_calloc(1, sizeof(t_list**));
	if (!head)
		error_handler(NULL, NULL);
	while (i < argc)
		split_input(argv[i++], head);
	list = *head;
	free(head);
	return (list);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_list *head;
	t_list *aux;

	head = get_list(argc, argv);
	aux = head;
	while (aux)
	{
		printf("%ld\n", *((long *)aux->content));
		aux = aux->next;
	}
	ft_lstclear(&head, free);
	(void)argc;
	(void)argv;
}

//TO DO 
// read from stdin
// check repeat