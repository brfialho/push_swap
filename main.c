/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:53:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/12 20:02:41 by brfialho         ###   ########.fr       */
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
#include <stdio.h>
void	print_stack(void *content)
{
	printf("NUMBER :%ld INDEX: %zu\n", ((t_number *)content)->number, ((t_number *)content)->index);
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
		error_handler(head, NULL);
	while (split[i])
		if(!append_node(split[i++], head))
			error_handler(head, split);
	ft_split_free(split);
}

t_list	**get_list(int argc, char* argv[])
{
	t_list	**head;
	int		i;

	if (argc < 2)
		exit(1);
	head = ft_calloc(1, sizeof(t_list**));
	if (!head)
		error_handler(NULL, NULL);
	i = 1;
	while (i < argc)
		split_input(argv[i++], head);
	return (head);
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

int	push_cmp_isgreater(void *i, void *j)
{
	return (((t_number *)i)->number > ((t_number *)j)->number);
}


int	push_cmp_isequal(void *i, void *j)
{
	return (((t_number *)i)->number == ((t_number *)j)->number);
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

void	assign_relative_value(t_list *lst,t_list *dup)
{
	t_list			*aux;
	unsigned long	len;

	len = 0;
	while (dup)
	{
		aux = lst_search(lst, dup->content, push_cmp_isequal);
		((t_number *)aux->content)->index = len++;
		dup = dup->next;
	}
}
int	is_sorted(t_list **head, t_list **dup)
{
	t_list	*lst;
	t_list	*dup_lst;

	lst = *head;
	dup_lst = *dup;
	while (lst)
	{
		if (((t_number *)lst->content)->number != \
		((t_number *)dup_lst->content)->number)
			return (FALSE);
		lst = lst->next;
		dup_lst = dup_lst->next;
	}
	lst_del_all(dup, NULL);
	lst_del_all(head, free);
	free(head);
	return (TRUE);
}
void	format_list(t_list** head)
{
	t_list*	dup;

	dup = lst_dup(*head, free);
	if (!dup)
		error_handler(head, NULL);
	lst_bubble_sort(dup, push_cmp_isgreater);
	if (check_for_repeats(&dup))
		error_handler(head, NULL);
	if (is_sorted(head, &dup))
		exit(0);
	assign_relative_value(*head, dup);
	lst_del_all(&dup, NULL);
}
void	init_stack_b(t_stacks *stack)
{
	stack->b = ft_calloc(1, sizeof(t_list**));
	if (!stack->b)	
		error_handler(stack->a, NULL);
}

unsigned long	push_lst_size(t_list *head)
{
	unsigned long	size;

	size = 0;
	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}

int	calculate_loops(t_list *lst)
{
	int				bits;
	unsigned long	mask;
	unsigned long	max_index;

	bits = sizeof(unsigned long) * BYTE;
	mask = MASK;
	max_index = push_lst_size(lst) - 1;
	while (!(mask & max_index) && bits--)
		mask = mask >> 1;
	return (bits++);
}

void	push_radix_sort(t_stacks *stack)
{
	int				loop;
	unsigned long	mask;
	unsigned long	i;
	unsigned long	len;

	len = push_lst_size(*stack->a);
	loop = calculate_loops(*stack->a);
	mask = 1;
	while (loop--)
	{
		i = 0;
		while (i++ < len)
			if (!(((t_number *)((t_list *)*stack->a)->content)->index & mask))
				pb(stack);
			else
				ra(stack, TRUE);
		while (i--)
			pa(stack);
		mask = mask << 1;
	}
}
void	push_sort_three(t_stacks *stack)
{
	unsigned long first;
	unsigned long second;

	first = ((t_number *)((t_list *)*stack->a)->content)->index;
	second = ((t_number *)((t_list *)*stack->a)->next->content)->index;

	if (first == 1 && second == 0)
		sa(stack, TRUE);
	else if (first == 1 && second == 2)
		rra(stack, TRUE);
	else if (first == 2 && second == 0)
		ra(stack, TRUE);
	else if (first == 2 &&
			ra(stack, TRUE))
		sa(stack, TRUE);
	else if (\
		rra(stack, TRUE))
		sa(stack, TRUE);
}

int	main(int argc, char *argv[])
{
	t_stacks stack;

	stack.a = get_list(argc, argv);
	format_list(stack.a);
	init_stack_b(&stack);

	// ft_printf("A:\n");
	// lst_for_each(*stack.a, print_stack);
	// printf("\n");

	push_sort_three(&stack);

	// ft_printf("A:\n");
	// lst_for_each(*stack.a, print_stack);
	// printf("\n");

	lst_del_all(stack.a, free);
	lst_del_all(stack.b, free);
	free(stack.a);
	free(stack.b);
}
