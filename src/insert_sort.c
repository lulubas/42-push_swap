/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:25:24 by lbastien          #+#    #+#             */
/*   Updated: 2023/04/20 11:25:30 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_insertsort(t_int **stacka, t_int **stackb)
{
	if (ft_check_sorted(*stacka))
		return ;
	while (*stacka)
	{
		do_pb(stacka, stackb);
		ft_insert(stackb);
	}
	while (*stackb)
		do_pa(stacka, stackb);
}

void	ft_insert(t_int **stackb)
{
	int		insert_index;
	int		count;

	insert_index = ft_find_index(*stackb);
	count = 0;
	while (insert_index)
	{
		do_sb(stackb);
		if (insert_index > 1)
		{
			do_rb(stackb);
			count++;
		}
		insert_index--;
	}
	while (count--)
		do_rrb(stackb);
}

int	ft_find_index(t_int *stack)
{
	t_int	*check;
	int		value;
	int		i;

	check = stack->next;
	value = stack->num;
	i = 0;
	while (check)
	{
		if (value > check->num)
			return (i);
		check = check->next;
		i++;
	}
	return (i);
}