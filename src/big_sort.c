/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:48:54 by lbastien          #+#    #+#             */
/*   Updated: 2023/05/24 14:49:09 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_bigsort(t_int **stacka, t_int **stackb)
{
	static int	sorted;
	t_int		*partition_b;

	partition_b = NULL;
	while ((ft_intlst_size(*stackb) != 0 || \
		!ft_check_sorted(*stacka, ft_intlst_size(*stacka))))
	{
		if (!ft_check_sorted(*stacka, ft_intlst_size(*stacka)))
			ft_sort_a(stacka, stackb, sorted, &partition_b);
		else
		{
			sorted = ft_intlst_size(*stacka);
			ft_sort_b(stacka, stackb, &partition_b);
		}
	}
	free_list(partition_b);
}

int	ft_sort_a(t_int **stacka, t_int **stackb, int sorted, t_int **partition_b)
{
	int	remain;
	int	pushed;

	if (ft_check_sorted(*stacka, ft_intlst_size(*stacka)))
		return (ft_intlst_size(*stacka) - sorted);
	while (ft_intlst_size(*stacka) - sorted > 3)
	{
		pushed = ft_split_a(stacka, stackb, ft_intlst_size(*stacka) - sorted);
		ft_intlst_addfront(partition_b, ft_intlst_new(pushed));
	}
	remain = ft_intlst_size(*stacka) - sorted;
	ft_nanosort_a(stacka, remain);
	return (remain);
}

void	ft_sort_b(t_int **stacka, t_int **stackb, t_int **partition_b)
{
	if (ft_check_sorted_rev(*stackb, (*partition_b)->num))
	{	
		do_pa(stacka, stackb, (*partition_b)->num);
		ft_freetop(partition_b);
		return ;
	}
	if ((*partition_b)->num <= 3)
		ft_nanosort_b(stacka, stackb, partition_b);
	else
		(*partition_b)->num -= ft_split_b(stacka, stackb, (*partition_b)->num);
}

void	ft_nanosort_a(t_int **stacka, int len)
{
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if ((*stacka)->num > (*stacka)->next->num)
			do_sa(stacka);
	}
	else if (len == 3)
	{
		while (!ft_check_sorted(*stacka, 3))
		{
			if ((*stacka)->num > (*stacka)->next->num)
				do_sa(stacka);
			if (!ft_check_sorted(*stacka, 3))
			{
				do_ra(stacka, 1);
				do_sa(stacka);
				do_rra(stacka, 1);
			}
		}
	}
}

void	ft_nanosort_b(t_int **stacka, t_int **stackb, t_int **partition_b)
{
	if ((*partition_b)->num == 2)
	{
		do_sb(stackb);
		do_pa(stacka, stackb, 2);
	}
	else if ((*partition_b)->num == 3)
	{
		while (!ft_check_sorted_rev(*stackb, 3))
		{
			if ((*stackb)->num < (*stackb)->next->num)
				do_sb(stackb);
			if (!ft_check_sorted_rev(*stackb, 3))
			{
				do_rb(stackb, 1);
				do_sb(stackb);
				do_rrb(stackb, 1);
			}
		}
		do_pa(stacka, stackb, 3);
	}
	ft_freetop(partition_b);
}
