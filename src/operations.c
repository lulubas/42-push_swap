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

void	do_pa(int_list **stacka, int_list **stackb)
{
	int_list	*node;

	node = ft_intlst_new((*stackb)->num);
	ft_intlst_addfront(stacka, node);
	ft_freetop(stackb);
	ft_printf("pa\n");
}


void	do_pb(int_list **stacka, int_list **stackb)
{
	int_list	*node;
	node = ft_intlst_new((*stacka)->num);
	ft_intlst_addfront(stackb, node);
	ft_freetop(stacka);
	ft_printf("pb\n");
}

void	do_sb(int_list **stackb)
{
	int_list	*node;

	node = ft_intlst_new((*stackb)->num);
	node->next = (*stackb)->next->next;
	(*stackb)->next->next = node;
	ft_freetop(stackb);
	ft_printf("sb\n");
}

void	do_rb(int_list **stackb)
{
	int_list	*node;

	node = ft_intlst_new((*stackb)->num);
	ft_intlst_addback(stackb, node);
	ft_freetop(stackb);
	ft_printf("rb\n");
}

void	do_rrb(int_list **stackb)
{
	int_list	*node;
	
	node = ft_intlst_new(ft_intlst_last(*stackb)->num);
	ft_intlst_addfront(stackb, node);
	ft_freebottom(*stackb);
	ft_printf("rbb\n");
}
/*
void	ra(int_list *stacka)
{
	int_list	*node;

	node = ft_intlst_new(stacka->num);
	ft_intlst_addback(&stacka, node);
	ft_printf("ra\n");
}

int_list	*pa(int_list **stacka, int_list *stackb)
{
	int_list	*node;
	node = ft_intlst_new(stackb->num);
	ft_intlst_addfront(stacka, node);
	ft_freetop(stackb);
	ft_printf("pa\n");
	return (stackb);
}
*/

void ft_freetop(int_list **lst)
{
	int_list	*tmp;

	tmp = *lst;
	*lst = tmp->next;
	free(tmp);
}

void ft_freebottom(int_list *stack)
{
	int_list	*second_to_last;
	int_list	*tmp;

	if(stack == NULL || stack->next == NULL)
		return ;
	second_to_last = stack;
	while(second_to_last->next->next != NULL)
		second_to_last = second_to_last->next;
	tmp = second_to_last->next;
	second_to_last->next = NULL;
	free(tmp);
}