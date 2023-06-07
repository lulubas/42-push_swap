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
		ft_bigsort(stacka, stackb);
}

void	free_node(t_int *node)
{
	if (node)
	{
		free(node);
		node = NULL;
	}
}

void	free_list(t_int *list)
{
	t_int	*tmp;

	tmp = list;
	while (tmp)
	{
		list = list->next;
		free_node(tmp);
		tmp = list;
	}
}
