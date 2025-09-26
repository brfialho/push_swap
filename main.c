/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:53:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/09/26 17:31:30 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	validate_chars(char *s)
{
	while (*s)
		if (!ft_isnumspace(*s++))
			return (0);
	return (1);
}

void	fill_numbers(int	*numbers, char	**split)
{
	int	i;
	
	i = -1;
	while (split[++i])
		numbers[i] = ft_atoi(split[i]);
	ft_split_free(split);
}

int	*split_input(char *input)
{
	char	**split;
	int 	*numbers;

	if (!validate_chars(input))
		return (NULL);
	split = ft_split(input, ' ');
	if (!split)
		return (NULL);
	numbers = ft_calloc(ft_split_len(split), sizeof(int));
	if (!numbers)
		return (ft_split_free(split), NULL);
	fill_numbers(numbers, split);
	return (numbers);
}

int	*get_input(int argc, char* argv[])
{
	if (argc > 2)
		return (NULL);
	if (argc == 2)
		return (split_input(argv[1]));
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int	*input;

	input = get_input(argc, argv);
	if (!input)
		return (write(2, "Error\n", 6));
	for(int i = 0; i < 4; i++)
		ft_printf("%d\n", input[i]);
	free(input);
}

//TO DO 

// STRING 
// check int max / int min
// keep track of int array size

// INT
// implement logic