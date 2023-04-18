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
	int_list	*stacka;
	int_list	*stackb;

	stacka = ft_parse_input(argc, argv);
	stackb = NULL;
	if (!stacka)
		return (0);
	ft_insertsort(&stacka, &stackb);
	ft_print_stacks(stacka, stackb);
	return (0);
}

void ft_insertsort(int_list **stacka, int_list **stackb)
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

void ft_insert(int_list **stackb)
{
	int			insert_index;
	int			count;

	insert_index = ft_find_index(*stackb);
	count = 0;
	while(insert_index)
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

int		ft_find_index(int_list *stack)
{
		int_list	*check;
		int			value;
		int			i;
		
		check = stack->next;
		value = stack->num;
		i = 0;
		while(check)
		{
			if(value > check->num)
				return (i);
			check = check->next;
			i++;
		}
		return(i);
}

/*
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
*/