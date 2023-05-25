/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:28:11 by lbastien          #+#    #+#             */
/*   Updated: 2023/03/22 15:28:16 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int ft_split(t_int **stacka, t_int **stackb, int len)
{
	int	median;
	int i;
	int count;

	i = 0;
	count = 0;
	median = ft_find_median(*stacka, len);
//	ft_printf("median=%d\n", median);
	while (i < len)
	{
		if ((*stacka)->num < median)
		{
			do_pb(stacka, stackb);
			count++;
		}
		else if (i != len - 1)
			do_ra(stacka);
		i++;
	}
	return(count);
}

int	ft_find_median(t_int *stack, int len)
{
	int 	*array;
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