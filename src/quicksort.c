/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:28:11 by lbastien          #+#    #+#             */
/*   Updated: 2023/03/22 15:28:16 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_qsort(int *array, int beg, int end)
{
	int	pivot;

	if (beg < end)
	{
		pivot = ft_partition (array, beg, end);
		ft_qsort (array, beg, pivot - 1);
		ft_qsort (array, pivot + 1, end);
	}
}

int	ft_partition(int *array, int beg, int end)
{
	int	pivot;
	int	checker;
	int	greater;

	pivot = array[end];
	greater = beg - 1;
	checker = beg;
	while (checker < end)
	{
		if (array[checker] < pivot)
		{
			greater++;
			ft_swap(&array[greater], &array[checker]);
		}
		checker++;
	}
	ft_swap(&array[greater + 1], &array[end]);
	return (greater + 1);
}

void	ft_swap(int *a, int	*b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_find_median(t_int *stack, int len)
{
	int		*array;
	t_int	*head;
	int		i;

	i = 0;
	head = stack;
	array = (int *)malloc(sizeof(int) * (len));
	if (!array)
		return (0);
	while (head && i < len)
	{
		array[i] = head->num;
		head = head->next;
		i++;
	}
	ft_qsort(array, 0, len - 1);
	i = array[len / 2];
	free(array);
	return (i);
}
