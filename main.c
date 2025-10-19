/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:53:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/19 00:18:27 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	t_stacks	stack;
	long		len;

	stack.a = get_list(argc, argv);
	format_list(stack.a);
	init_stack_b(&stack);
	len = push_lst_size(*stack.a);
	if (len == 3)
		push_sort_three(&stack);
	else if (len == 5)
		push_sort_five(&stack);
	else
		push_radix_sort(&stack);
	lst_del_all(stack.a, free);
	lst_del_all(stack.b, free);
	free(stack.a);
	free(stack.b);
}

// #include <stdio.h>
// void	print_stack(void *content)
// {
// 	printf("NUMBER :%ld\n", *(long *)content);
// }
// int	main(int argc, char *argv[])
// {
// 	t_stacks	stack;
// 	long		len;

// 	stack.a = get_list(argc, argv);

// 	ft_printf("AA:\n");
// 	lst_for_each(*stack.a, print_stack);
// 	printf("\n");

// 	format_list(stack.a);
// 	init_stack_b(&stack);

// 	ft_printf("A:\n");
// 	lst_for_each(*stack.a, print_stack);
// 	printf("\n");

// 	len = push_lst_size(*stack.a);
// 	if (len == 3)
// 		push_sort_three(&stack);
// 	else if (len == 5)
// 		push_sort_five(&stack);
// 	else
// 		push_radix_sort(&stack);

// 	ft_printf("A:\n");
// 	lst_for_each(*stack.a, print_stack);
// 	printf("\n");

// 	lst_del_all(stack.a, free);
// 	lst_del_all(stack.b, free);
// 	free(stack.a);
// 	free(stack.b);
// }