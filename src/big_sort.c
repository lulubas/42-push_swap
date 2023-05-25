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
	t_int	*partition_b;

	partition_b = NULL;
	sorted += ft_sort_a(stacka, stackb, sorted, &partition_b);
	ft_sort_b(stacka, stackb, &partition_b);
}

int ft_sort_a(t_int **stacka, t_int **stackb, int sorted, t_int **partition_b)
{
	int pushed;

	while (ft_intlst_size(*stacka) > 2)
	{
			pushed = ft_split(stacka, stackb, ft_intlst_size(*stacka));
			ft_intlst_addfront(partition_b, ft_intlst_new(pushed));
	}
	ft_nanosort_a(stacka, ft_intlst_size(*stacka) - sorted);
	return (pushed);
}

void ft_sort_b(t_int **stacka, t_int **stackb, t_int **partition_b)
{
	if ((*partition_b)->num <= 2)
		ft_nanosort_b(stacka, stackb, partition_b);
	else
		(*partition_b)->num -= ft_split_b(stacka, stackb, (*partition_b)->num);
}

int ft_split_b(t_int **stacka,t_int **stackb, int len)
{
	int	median;
	int i;
	int	count_pa;
	int count_rb;

	i = 0;
	count_pa = 0;
	count_rb = 0;
	median = ft_find_median(*stackb, len);
	while (i < len)
	{
		if ((*stackb)->num > median)
		{
			do_pa(stacka, stackb);
			count_pa++;
		}
		else if (i != len - 1)
		{
			do_rb(stackb);
			count_rb++;
		}
		i++;
	}
	while (count_rb)
	{
		do_rrb(stackb);
		count_rb--;
	}
	return(count_pa);
}

void	ft_nanosort_a(t_int **stacka, int len)
{
	if(len == 1)
		return ;
	if ((*stacka)->num > (*stacka)->next->num)
		do_sa(stacka);
}

void	ft_nanosort_b(t_int **stacka, t_int **stackb, t_int **partition_b)
{
	if((*partition_b)->num == 1)
	{
		do_pa(stacka, stackb);
		return ;
	}
	if ((*stackb)->num < (*stackb)->next->num)
		do_sb(stacka);
	do_pa(stacka, stackb);
	do_pa(stacka, stackb);
	ft_freetop(partition_b);
}