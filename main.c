/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:53:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/26 19:32:40 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	error_handler(void)
{
	ft_printf("Error\n");
	exit(1);
}
int	validate_chars(char *s)
{
	while (*s)
		if (!ft_isnumspace(*s++))
			return (0);
	return (1);
}

long	push_atol(char *s)
{
	long	sum;
	int	sign;

	sign = 1;
	sum = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	while (ft_isdigit(*s))
		sum = sum * 10 + *s++ - '0';
	return (sum * sign);
}

void	append_node(char *input, t_list **head)
{
	t_list	*new;
	long	n;

	n = push_atol(input);
	if (n > INT_MAX || n < INT_MIN)
		error_handler();
	new = ft_lstnew(&n);
	if (!new)
		error_handler();
	if (!*head)
		*head = new;
	else
		(*head)->next = new;
}
void	split_input(char *s, t_list **head)
{
	int		i;
	char	**split;

	i = 0;
	
	split = ft_split(s, ' ');
	if (!split)
		error_handler();

	while (split[i])
		append_node(split[i++], head);

	ft_split_free(split);
}


t_list	*get_list(int argc, char* argv[])
{
	t_list	**head;
	t_list	*list;
	int		i;

	if (argc < 2)
		error_handler();
	i = 1;
	head = ft_calloc(1, sizeof(t_list**));
	if (!head)
		error_handler();
	while (i < argc)
		split_input(argv[i++], head);
	list = *head;
	free(head);
	return (list);
}

int	main(int argc, char *argv[])
{
	t_list *head;

	head = get_list(argc, argv);
	if (!head)
		error_handler();
	
	while (head && ft_printf("%d\n", head->content))
		(head) = head->next;
}

//TO DO 

// STRING 
// check int max / int min
// keep track of int array size

// INT
// implement logic