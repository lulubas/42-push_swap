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
	t_int	*stacka;
	t_int	*stackb;

	stacka = ft_parse_input(argc, argv);
	stackb = NULL;
	if (!stacka)
		return (0);
	ft_sort(&stacka, &stackb, argc);
//	ft_print_stacks(stacka, stackb);
	free_list(stacka);
	free_list(stackb);
	return (0);
}

void	ft_sort(t_int **stacka, t_int **stackb, int argc)
{
	int	args;

	args = argc - 1;
	if (args <= 6)
		ft_smallsort(stacka, stackb, args);
	else
		ft_insertsort(stacka, stackb);
}

/*
t_int	*ft_quicksort(t_int	*stack)
{
	t_int	*tail;
	t_int	*head;

	tail = ft_intlst_last(stack);
	head = ft_pivot(stack, tail);
	return (head);
}

t_int	*ft_pivot(t_int *head, t_int *tail)
{
	t_int	*stackb;
	t_int	*pivot;
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
//	ft_print_stacks(stacka, stackb);