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

void	do_ra(t_int **stacka, int num)
{
	t_int	*node;

	while (num--)
	{
		node = ft_intlst_new((*stacka)->num);
		ft_intlst_addback(stacka, node);
		ft_freetop(stacka);
		ft_printf("ra\n");
	}	
}

void	do_rb(t_int **stackb, int num)
{
	t_int	*node;

	while (num--)
	{
		node = ft_intlst_new((*stackb)->num);
		ft_intlst_addback(stackb, node);
		ft_freetop(stackb);
		ft_printf("rb\n");
	}
}

void	do_rra(t_int **stacka, int num)
{
	t_int	*node;

	while (num--)
	{
		node = ft_intlst_new(ft_intlst_last(*stacka)->num);
		ft_intlst_addfront(stacka, node);
		ft_freebottom(*stacka);
		ft_printf("rra\n");
	}
}

void	do_rrb(t_int **stackb, int num)
{
	t_int	*node;

	while (num--)
	{
		node = ft_intlst_new(ft_intlst_last(*stackb)->num);
		ft_intlst_addfront(stackb, node);
		ft_freebottom(*stackb);
		ft_printf("rrb\n");
	}
}
