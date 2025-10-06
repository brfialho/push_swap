/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:53:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/06 18:04:43 by brfialho         ###   ########.fr       */
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
#include <stdio.h>
void	print_stack(void *content)
{
	printf("NUMBER :%ld\n", ((t_number *)content)->number);
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

t_list	**get_list(int argc, char* argv[])
{
	t_list	**head;
	int		i;

	if (argc < 2)
		exit(1);
	head = ft_calloc(1, sizeof(t_list**));
	if (!head)
		error_handler(NULL, NULL, NULL);
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
	t_list	*aux;
	long	len;

	len = 0;
	while (dup)
	{
		aux = lst_search(lst, dup->content, push_cmp_isequal);
		((t_number *)aux->content)->index = len++;
		dup = dup->next;
	}
}

void	format_list(t_list** head)
{
	t_list*	dup;

	dup = lst_dup(*head, free);
	if (!dup)
		error_handler(head, *head, NULL);
	lst_bubble_sort(dup, push_cmp_isgreater);
	if (check_for_repeats(&dup))
		error_handler(head, *head, NULL);
	assign_relative_value(*head, dup);
	
	// lst_for_each(*head, print_stack);
	// ft_printf("\n");
		
	lst_del_all(&dup, NULL);
}
void	init_stack_b(t_stacks *stack)
{
	stack->b = ft_calloc(1, sizeof(t_list**));
	if (!stack->b)	
		error_handler(stack->a, *stack->a, NULL);
}

//sa
//sb
//ss
//pa
//pb
//ra
//rb
//rr
//rra
//rrb
//rrr

void	pb(t_stacks *stack)
{
	if (!*stack->a)
		return ;
	lst_add_start(stack->b, lst_detach(stack->a, *stack->a));
	write(1, "pb\n", 3);
}

void	pa(t_stacks *stack)
{
	if (!*stack->b)
		return ;
	lst_add_start(stack->a, lst_detach(stack->b, *stack->b));
	write(1, "pa\n", 3);
}
void	rra(t_stacks *stack, int print)
{
	if (!*stack->a)
		return ;
	lst_add_start(stack->a, lst_detach(stack->a , lst_last(*stack->a)));
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stacks *stack, int print)
{
	if (!*stack->b)
		return ;
	lst_add_start(stack->b, lst_detach(stack->b , lst_last(*stack->b)));
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stack)
{
	rra(stack, FALSE);
	rrb(stack, FALSE);
	write(1, "rrr\n", 4);
}

void	ra(t_stacks *stack, int print)
{
	if (!*stack->a)
		return ;
	lst_add_end(stack->a, lst_detach(stack->a, *stack->a));
	if (print)
		write(1, "ra\n", 3);
}
void	rb(t_stacks *stack, int print)
{
	if (!*stack->b)
		return ;
	lst_add_end(stack->b, lst_detach(stack->b, *stack->b));
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stacks *stack)
{
	ra(stack, FALSE);
	rb(stack, FALSE);
	write(1, "rr\n", 3);
}



int	main(int argc, char *argv[])
{
	t_stacks stack;

	stack.a = get_list(argc, argv);
	format_list(stack.a);
	init_stack_b(&stack);

	ft_printf("A:\n");
	lst_for_each(*stack.a, print_stack);
	ft_printf("\n");
	
	// ra(&stack, TRUE);
	rr(&stack);
	ft_printf("A:\n");
	lst_for_each(*stack.a, print_stack);
	ft_printf("\n");

	
	lst_del_all(stack.a, free);
	lst_del_all(stack.b, free);
	free(stack.a);
	free(stack.b);

// 	(void)argc;
// 	(void)argv;
}

//TO DO
// refator code to be more readable
