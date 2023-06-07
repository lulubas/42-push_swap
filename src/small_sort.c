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

void	ft_mediumsort(t_int **stacka, t_int **stackb, int args)
{	
	ft_split(stacka, stackb, args);
	ft_minisort(stacka);
	ft_minisort_rev(stackb);
	do_pa(stacka, stackb, ft_intlst_size(*stackb));
}

void	ft_minisort(t_int **stacka)
{
	t_int	*head;
	t_int	*second;

	head = *stacka;
	second = head->next;
	if (ft_check_sorted(*stacka, ft_intlst_size(*stacka)))
		return ;
	if (head->num > second->num)
		do_sa(stacka);
	if (second->num > second->next->num)
		do_rra(stacka, 1);
	ft_minisort(stacka);
}

void	ft_minisort_rev(t_int **stackb)
{
	t_int	*head;
	t_int	*second;

	head = *stackb;
	second = head->next;
	if (ft_check_sorted_rev(*stackb, ft_intlst_size(*stackb)))
		return ;
	if (head->num < second->num)
		do_sb(stackb);
	if (second->num < second->next->num)
		do_rrb(stackb, 1);
	ft_minisort_rev(stackb);
}
