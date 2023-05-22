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
void	ft_smallsort(t_int **stacka, t_int **stackb, int args)
{
	if (args <= 3)
		ft_smallsort_a(stacka);
	else
		ft_divide(stacka, stackb, args); 
}

void	ft_smallsort_a(t_int **stack)
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
	ft_smallsort_a(stack);
}

void	ft_smallsort_b(t_int **stack)
{
	t_int	*head;
	t_int	*second;
	
	head = *stack;
	second = head->next;
	if (ft_check_sorted_rev(*stack))
		return ;
	if (head->num < second->num)
		do_sb(stack);
	if (second->num < second->next->num)
		do_rrb(stack);
	ft_smallsort_b(stack);
}

void ft_divide(t_int **stacka, t_int **stackb, int args)
{
	int	median;
	int i;

	i = 0;
	median = ft_find_median(*stacka, args);
	while (i < args)
	{
		if ((*stacka)->num < median)
			do_pb(stacka, stackb);
		else if (i != args - 1)
			do_ra(stacka);
		i++;
	}
	ft_smallsort_a(stacka);
	ft_smallsort_b(stackb);
	ft_empty_pa(stacka, stackb);
}

void	ft_empty_pa(t_int **stacka, t_int **stackb)
{
	t_int *tmp;

	tmp = *stackb;
	while (tmp != NULL)
	{
		do_pa(stacka, stackb);
		tmp = tmp->next;
	}
}

int	ft_find_median(t_int *stack, int args)
{
	int 	*array;
	t_int	*head;
	int		i;

	i = 0;
	head = stack;
	array = (int *)malloc(sizeof(int) * (args));
	if (!array)
		return (0);
	while (head)
	{
		array[i] = head->num;
		head = head->next;
		i++;
	}
	ft_qsort(array, 0, args - 1);
	i = array[args / 2];
	free(array);
	return (i);
}

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
	int checker;
	int greater;
	
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

void	ft_swap(int *a, int	*b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}