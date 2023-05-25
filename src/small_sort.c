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
		ft_minisort(stacka);
	else
		ft_mediumsort(stacka, stackb, args); 
}

void	ft_minisort(t_int **stack)
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
	ft_minisort(stack);
}

void	ft_minisort_rev(t_int **stack)
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
	ft_minisort_rev(stack);
}

void ft_mediumsort(t_int **stacka, t_int **stackb, int args)
{	
	ft_split(stacka, stackb, args);
	ft_minisort(stacka);
	ft_minisort_rev(stackb);
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