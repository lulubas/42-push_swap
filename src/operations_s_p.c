/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:16:01 by lbastien          #+#    #+#             */
/*   Updated: 2023/04/20 13:16:03 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	do_sa(t_int **stacka)
{
	t_int	*node;

	node = ft_intlst_new((*stacka)->num);
	node->next = (*stacka)->next->next;
	(*stacka)->next->next = node;
	ft_freetop(stacka);
	ft_printf("sa\n");
}

void	do_sb(t_int **stackb)
{
	t_int	*node;

	node = ft_intlst_new((*stackb)->num);
	node->next = (*stackb)->next->next;
	(*stackb)->next->next = node;
	ft_freetop(stackb);
	ft_printf("sb\n");
}

void	do_pa(t_int **stacka, t_int **stackb)
{
	t_int	*node;

	node = ft_intlst_new((*stackb)->num);
	ft_intlst_addfront(stacka, node);
	ft_freetop(stackb);
	ft_printf("pa\n");
}

void	do_pb(t_int **stacka, t_int **stackb)
{
	t_int	*node;

	node = ft_intlst_new((*stacka)->num);
	ft_intlst_addfront(stackb, node);
	ft_freetop(stacka);
	ft_printf("pb\n");
}