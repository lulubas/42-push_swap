/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:20:01 by lbastien          #+#    #+#             */
/*   Updated: 2023/04/18 17:20:03 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_freetop(t_int **lst)
{
	t_int	*tmp;

	tmp = *lst;
	*lst = tmp->next;
	free(tmp);
}

void	ft_freebottom(t_int *stack)
{
	t_int	*second_to_last;
	t_int	*tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	second_to_last = stack;
	while (second_to_last->next->next != NULL)
		second_to_last = second_to_last->next;
	tmp = second_to_last->next;
	second_to_last->next = NULL;
	free(tmp);
}
