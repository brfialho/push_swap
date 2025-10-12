/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 23:07:50 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/12 00:14:46 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

typedef struct s_pivot
{
	int first;
	int second;
}	t_pivot;

static void	swap(int *array, int j, int i)
{
	int	tmp;

	tmp = array[j];
	array[j] = array[i];
	array[i] = tmp;
}

static void	partition(int *array, int start, int end, t_pivot *pivot_index)
{
	int	i;
	int	j;
	int	k;

	i = start - 1;
	j = start - 1;
	k = end + 1;

	if (array[end] < array[start])
		swap(array, start, end);
	pivot_index->first = array[start];
	pivot_index->second = array[end];
	while (++j < end)
		if (array[j] < pivot_index->first)
			swap(array, j, ++i);
		else if (array[j] > pivot_index->second && j-- > -1)
			swap(array, j, --k);
	swap(array, i + 1, end);
	swap(array, k - 1, start);
	pivot_index->first = i + 1;
	pivot_index->second = k - 1;
}

static void	recursive_helper(int *array, int start, int end, t_pivot *pivot_index)
{
	if (end - start < 1)
		return ;
	
	partition(array, start, end, pivot_index);

	recursive_helper(array, start, pivot_index->first - 1, pivot_index);
	recursive_helper(array,  pivot_index->first + 1, pivot_index->second - 1, pivot_index);
	recursive_helper(array, pivot_index->second + 1, end, pivot_index);
}

int	ft_dual_quick_sort(int *array, int start, int end)
{
	t_pivot *pivot_index;

	pivot_index = ft_calloc(1, sizeof(t_pivot));
	if (!pivot_index)
		return (FALSE);

	recursive_helper(array, start, end, pivot_index);

	free(pivot_index);
	return (TRUE);
}

int main(void)
{
	// int size = 5;
	// int array[5] = {30, 10, 40, 80, 90};
	int size = 14;
	int array[14] = {5, 4, 3, 2, 1, 11, 200, 0 , 5, 5, -10, -128, 1111, 2000};
	ft_printf("BEFORE:\n");
	for (int i = 0; i < size; i++)
		ft_printf("%d ", array[i]);
	ft_printf("\n");

	ft_dual_quick_sort(array, 0, size - 1);

	ft_printf("AFTER:\n");
	for (int j = 0; j < size; j++)
		ft_printf("%d ", array[j]);
	ft_printf("\n");
}