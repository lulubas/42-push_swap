/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:03:26 by lbastien          #+#    #+#             */
/*   Updated: 2023/06/07 19:03:34 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	ft_split(t_int **stacka, t_int **stackb, int len)
{
	int	median;
	int	i;
	int	count;

	i = 0;
	count = 0;
	median = ft_find_median(*stacka, len);
	while (i < len)
	{
		if ((*stacka)->num < median)
		{
			do_pb(stacka, stackb);
			count++;
		}
		else if (i != len - 1)
			do_ra(stacka, 1);
		i++;
	}
	return (count);
}

int	ft_split_a(t_int **stacka, t_int **stackb, int len)
{
	int	median;
	int	count;
	int	count_ra;

	count = 0;
	count_ra = 0;
	median = ft_find_median(*stacka, len);
	while (len--)
	{
		if ((*stacka)->num < median)
		{
			do_pb(stacka, stackb);
			count++;
		}
		else if (len)
		{
			do_ra(stacka, 1);
			count_ra++;
		}
	}
	ft_return_a_to_start(stacka, count_ra);
	return (count);
}

int	ft_split_b(t_int **stacka, t_int **stackb, int len)
{
	int	median;
	int	count_pa;
	int	count_rb;

	count_pa = 0;
	count_rb = 0;
	median = ft_find_median(*stackb, len);
	while (len--)
	{
		if ((*stackb)->num >= median)
		{
			do_pa(stacka, stackb, 1);
			count_pa++;
		}
		else if (len)
		{
			do_rb(stackb, 1);
			count_rb++;
		}
	}
	ft_return_b_to_start(stackb, count_rb);
	return (count_pa);
}

void	ft_return_a_to_start(t_int **stacka, int count_ra)
{
	int	size;

	size = ft_intlst_size(*stacka);
	if (count_ra == size)
		return ;
	else if (size - count_ra < count_ra)
		do_ra(stacka, size - count_ra);
	else
		do_rra(stacka, count_ra);
}

void	ft_return_b_to_start(t_int **stackb, int count_rb)
{
	int	size;

	size = ft_intlst_size(*stackb);
	if (count_rb == size)
		return ;
	else if (size - count_rb < count_rb)
		do_rb(stackb, size - count_rb);
	else
		do_rrb(stackb, count_rb);
}
