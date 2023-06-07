/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:28:11 by lbastien          #+#    #+#             */
/*   Updated: 2023/03/22 15:28:16 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

t_int	*ft_parse_input(int argc, char **argv)
{		
	t_int		*node;
	t_int		*stack;
	int			num;
	int			i;

	stack = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (!ft_checks(argv[i], stack))
		{
			ft_printf("%E");
			free_list(stack);
			return (0);
		}
		num = ft_strtoint(argv[i]);
		node = ft_intlst_new(num);
		ft_intlst_addback(&stack, node);
		i++;
	}
	return (stack);
}

int	ft_checks(char *str, t_int *list)
{
	long		num;
	int			i;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
		if (!str[i])
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || i > 11)
			return (0);
		num = (str[i] - 48) + (num * 10);
		i++;
	}
	if ((num * sign) > 2147483647 || (num * sign) < -2147483648 \
		|| ft_duplicate(num * sign, list))
		return (0);
	return (1);
}

int	ft_duplicate(int num, t_int *list)
{
	t_int	*tmp;

	tmp = list;
	while (tmp)
	{
		if (num == tmp->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_strtoint(char *str)
{
	int	sign;
	int	i;
	int	num;

	sign = 1;
	i = 0;
	num = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}	
	while (str[i])
	{
		num = (str[i] - 48) + (num * 10);
		i++;
	}
	return ((num * sign));
}
