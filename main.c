/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:53:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/27 18:59:40 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	error_handler(t_list **head, char **split)
{
	if (head)
	{
		if (*head)
			lst_del_all(head, free);
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
	new = lst_new_node(n);
	if (!new)
		return (free(n), 0);
	if (!*head)
		*head = new;
	else
		lst_add_end(head, new);
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
		exit(1);
	head = ft_calloc(1, sizeof(t_list**));
	if (!head)
		error_handler(NULL, NULL);
	i = 1;
	while (i < argc)
		split_input(argv[i++], head);
	list = *head;
	free(head);
	return (list);
}

void	*push_copy_content(void	*content)
{
	long	*copy;

	if (!content)
		return (NULL);
	copy = ft_calloc(1, sizeof(long));
	if (!copy)
		return (NULL);
	*copy = *(long *)content;
	return (copy);
}

int	push_cmp_content(void *i, void *j)
{
	return (*(long *)i > *(long *)j);
}

#include <stdio.h>
void	check_for_repeats(t_list** head)
{
	t_list*	dup;

	dup = lst_dup(*head, push_copy_content, free);
	lst_bubble_sort(dup, push_cmp_content);

	lst_del_all(&dup, free);
	// t_list* tmp = dup;
	// while (tmp && printf ("DUP :%ld\n", *(long *)tmp->content))
	// 	tmp = tmp->next;
	// lst_del_all(&dup, free);
}
int	main(int argc, char *argv[])
{
	t_list *head;

	head = get_list(argc, argv);
	check_for_repeats(&head);
	
	lst_del_all(&head, free);

	// t_list* tmp = head;
	// while (tmp && printf ("HEAD: %ld\n", *(long *)tmp->content))
	// 	tmp = tmp->next;
	// lst_del_all(&head, free);
	// (void)argc;
	// (void)argv;
}

//TO DO
// check repeat
// refator code to be more readable
