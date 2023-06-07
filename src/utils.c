/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:28:11 by lbastien          #+#    #+#             */
/*   Updated: 2023/03/22 15:28:16 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_print_stacks(t_int *stacka, t_int *stackb)
{
	ft_printf("Stack A: \n");
	ft_print_lst(stacka);
	ft_printf("Stack B: \n");
	ft_print_lst(stackb);
}

void	ft_print_lst(t_int *list)
{
	t_int	*tmp;

	if (!list)
		ft_printf("List is empty");
	tmp = list;
	while (tmp)
	{
		ft_printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
}

int	ft_check_sorted(t_int *stack, int len)
{
	t_int	*tmp;

	tmp = stack;
	while (tmp->next && len)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
		len--;
	}
	return (1);
}

int	ft_check_sorted_rev(t_int *stack, int len)
{
	t_int	*tmp;

	tmp = stack;
	while (tmp->next && len)
	{
		if (tmp->num < tmp->next->num)
			return (0);
		tmp = tmp->next;
		len--;
	}
	return (1);
}
