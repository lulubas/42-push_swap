/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:28:11 by lbastien          #+#    #+#             */
/*   Updated: 2023/03/22 15:28:16 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int_list	*stack;

	stack = ft_parse_input(argc, argv);
	if (!stack)
		return (0);
	stack = ft_quicksort(stack);
	ft_print_lst(stack);
	return (0);
}

int_list	*ft_quicksort(int_list	*stack)
{
	int_list	*tail;
	int_list	*head;

	tail = ft_intlst_last(stack);
	head = ft_pivot(stack, tail);
	return (head);
}

int_list	*ft_pivot(int_list *head, int_list *tail)
{
	int_list	*stackb;
	int_list	*pivot;
	int			i;

	pivot = tail;
	stackb = NULL;
	i = 0;
	while (head != pivot)
	{
		if (head->num < pivot->num)
		{
			stackb = pb(head, stackb);
			i++;
		}
		else if (head->num > pivot->num)
			ra(head);
		head = ft_freetop(head);
	}
	while (i--)
		stackb = pa(&head, stackb);
	return(head);
}

int_list	*pb(int_list *stacka, int_list *stackb)
{
	int_list	*node;
	
	node = ft_intlst_new(stacka->num);
	ft_intlst_addfront(&stackb, node);
	ft_printf("pb\n");
	return (stackb);
}

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
	stackb = ft_freetop(stackb);
	ft_printf("pa\n");
	return (stackb);
}

int_list *ft_freetop(int_list *lst)
{
	int_list	*tmp;

	tmp = lst;
	lst = lst->next;
	free(tmp);
	return (lst);
}