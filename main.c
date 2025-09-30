/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:53:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/30 00:25:19 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	error_handler(t_list **head, t_list *lst, char **split)
{
	if (head)
		free(head);
	if (lst)
		lst_del_all(&lst, free);
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
	t_list		*new;
	t_number	*n;

	n = ft_calloc(1, sizeof(t_number));
	if (!n)
		return (0);
	n->index = 0;
	n->number = push_atol(input);
	if (n->number > INT_MAX)
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
		error_handler(head, *head, NULL);
	while (split[i])
		if(!append_node(split[i++], head))
			error_handler(head, *head, split);
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
		error_handler(NULL, NULL, NULL);
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
	return (((t_number *)i)->number > ((t_number *)j)->number);
}

int	check_for_repeats(t_list **dup)
{
	t_list	*tmp;

	tmp = *dup;
	while (tmp && tmp->next)
	{
		if (((t_number *)tmp->content)->number == 
			((t_number *)tmp->next->content)->number)
			return (lst_del_all(dup, NULL), 1);
		tmp = tmp->next;
	}
	return (0);

}
// void	assign_relative_value(t_list *lst,t_list *dup)
// {
// 	t_list	*aux;
// 	long	len;

// 	len = 0;
// 	while (dup)
// 		aux = search(lst, dup->content);
// 		aux->content = len++;

// }

// 13 1 10 -1 7 3000 -10 -5 0
// -10 -5 -1 0 1 7 10 13 3000

// 7 4 6 2 5 8 3 1 0 

// either do a third list to not mess up indexes 
// or do struct


#include <stdio.h>
void	format_list(t_list* lst)
{
	t_list*	dup;

	dup = lst_dup(lst, free);
	if (!dup)
		error_handler(NULL, lst, NULL);
	lst_bubble_sort(dup, push_cmp_content);
	if (check_for_repeats(&dup))
		error_handler(NULL, lst, NULL);
	// assign_relative_value(lst, dup);
	// lst_del_all(&dup, NULL);
	

	t_list* tmp = dup;
	while (tmp && printf ("DUP :%ld\n", ((t_number *)tmp->content)->number))
		tmp = tmp->next;
	lst_del_all(&dup, NULL);
}
int	main(int argc, char *argv[])
{
	t_list *head;

	head = get_list(argc, argv);
	format_list(head);
	

	// lst_del_all(&head, free);

	t_list* tmp = head;
	while (tmp && printf ("HEAD: %ld\n", ((t_number *)tmp->content)->number))
		tmp = tmp->next;
	lst_del_all(&head, free);

// 	(void)argc;
// 	(void)argv;
}

//TO DO
// refator code to be more readable
