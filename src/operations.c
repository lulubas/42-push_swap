/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:22:25 by lbastien          #+#    #+#             */
/*   Updated: 2023/04/18 12:22:26 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

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

void	do_sb(t_int **stackb)
{
	t_int	*node;

	node = ft_intlst_new((*stackb)->num);
	node->next = (*stackb)->next->next;
	(*stackb)->next->next = node;
	ft_freetop(stackb);
	ft_printf("sb\n");
}

void	do_rb(t_int **stackb)
{
	t_int	*node;

	node = ft_intlst_new((*stackb)->num);
	ft_intlst_addback(stackb, node);
	ft_freetop(stackb);
	ft_printf("rb\n");
}

void	do_rrb(t_int **stackb)
{
	t_int	*node;

	node = ft_intlst_new(ft_intlst_last(*stackb)->num);
	ft_intlst_addfront(stackb, node);
	ft_freebottom(*stackb);
	ft_printf("rbb\n");
}
