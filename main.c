/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:53:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/27 00:25:44 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	error_handler(t_list **head, char **split, char *argv)
{
	if (head)
	{
		if (*head)
			ft_lstclear(head, free);
		free(head);
	}
	if (split)
		ft_split_free(split);
	if (argv)
		free(argv);
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

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;
	char	*tmp;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	join = ft_calloc(1, len + 1);
	if (!join)
		return (ft_free(&s1), ft_free(&s2), NULL);
	tmp = s1;
	if (tmp)
		while (*tmp)
			*join++ = *tmp++;
	tmp = s2;
	if (tmp)
		while (*tmp)
			*join++ = *tmp++;
	ft_free(&s1);
	ft_free(&s2);
	return (join - len);
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
		error_handler(head, NULL, s);
	while (split[i])
		if(!append_node(split[i++], head))
			error_handler(head, split, s);
	free(s);
	ft_split_free(split);
}

void remove_newline(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			s[i] = ' ';
}

t_list	*get_stdin_input(t_list **head)
{
	char	*input;
	char	*buffer;
	t_list	*list;

	input = 0;
	buffer = get_next_line(STDIN_FILENO);
	if (!buffer)
		error_handler(head, NULL, NULL);
	remove_newline(buffer);
	while (buffer)
	{
		input = ft_strjoin_free(input, buffer);
		if (!input)
			error_handler(head, NULL, NULL);
		buffer = get_next_line(STDIN_FILENO);
		if (buffer)
			remove_newline(buffer);
	}
	split_input(input, head);
	list = *head;
	free(head);
	return (list);
}

t_list	*get_list(int argc, char* argv[])
{
	t_list	**head;
	t_list	*list;
	char	*s;
	int		i;

	i = 1;
	head = ft_calloc(1, sizeof(t_list**));
	if (!head)
		error_handler(NULL, NULL, NULL);
	if (argc < 2)
		return (get_stdin_input(head));
	while (i < argc)
	{
		s = ft_strdup(argv[i++]);
		if (!s)
			error_handler(head, NULL, NULL);
		split_input(s, head);
	}
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
	printf("\n");
	while (aux)
	{
		printf("%ld\n", *((long *)aux->content));
		aux = aux->next;
	}
	ft_lstclear(&head, free);
	
	(void)argc;
	(void)argv;
	// char *str=NULL;
	// char *tmp;
	// while ((tmp = get_next_line(STDIN_FILENO)))
	// 	str = ft_strjoin_free(str, tmp);
	// 	// ft_printf("%d\n", tmp);
	// ft_printf("%s\n", str);
	// free(str);
}

//TO DO 
// read from stdin
// check repeat