/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:42:52 by lbastien          #+#    #+#             */
/*   Updated: 2023/04/20 12:44:37 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
void	ft_smallsort(t_int **stacka, t_int **stackb, int argc)
{
	if (argc < 5)
		ft_smallsort_a(stacka);
	else
		ft_divide(stacka, stackb, argc); 
}

void	ft_smallsort_a(t_int **stacka)
{
	t_int	*head;
	t_int	*second;
	
	head = *stack;
	second = head->next;
	if (ft_check_sorted(*stack))
		return ;
	if (head->num > second->num)
		do_sa(stack);
	if (second->num > second->next->num)
		do_rra(stack);
	ft_smallsort(stack);
}

void ft_divide(t_int **stacka, t_int **stackb, int argc)
{
	t_int *head;
	int	median;

	median = ft_find_median(*stacka, argc);

}

int	ft_find_median(t_int *stack, int argc)
{
	int 	*array;
	t_int	*head;
	int		i;
	int		median;

	i = 0;
	head = stack;
	array = (int *)malloc(sizeof(int) * (argc - 1));
	if (!array)
		return (NULL);
	while (head)
	{
		array[i++] = head->num;
		head = head->next;
	}
	ft_qsort(array, 0, argc - 1);
	if (argc % 2 == 0)
		return (array[(argc / 2) + 1])
	else
		return (array[argc / 2]);
}

void	*ft_qsort(int *array, int beg, int end)
{
	int	pivot;

	if (beg < end)
	{
		pivot = ft_partition (array, beg, end);
		ft_qsort (array, beg, pivot - 1);
		ft_qsort (array, pivot + 1, end);
	}
}

int	*ft_partition(int *array, int beg, int end)
{
	int	pivot;
	int left;
	int checker;
	
	pivot = array[end];
	greater = beg - 1;
	checker = beg;
	while (checker < end)
	{
		if(array[checker] < pivot)
		{
			greater++;
			ft_swap(&array[greater], &array[checker]);
		}
		checker++;
	}
	ft_swap(&array[greater + 1], &array[end]);
	return (greater + 1);
}

void	ft_swap(int *a, int	*b);
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}