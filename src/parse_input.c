/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:28:11 by lbastien          #+#    #+#             */
/*   Updated: 2023/03/22 15:28:16 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int_list	*ft_parse_input(int argc, char **argv)
{		
	int_list		*node;
	int_list		*stack;
	int			num;
	int			i;
	
	stack = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	while(i < argc)
	{
		if (!ft_checks(argv[i], i))
		{
			ft_printf("Error\n");
			return (0);
		}
		num = ft_strtoint(argv[i]);
		node = ft_intlst_new(num);
		ft_intlst_addback(&stack, node);
		i++;
	}
	return (stack);
}

int		ft_checks(char *str, int index)
{
	long		num;
	int			i;
	int 		sign;
	static int	previous;

	i = 0;
	num = 0;
	sign = 1;
	if(str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if(!ft_isdigit(str[i]) || i > 11)
			return (0);
		num = (str[i] - 48) + (num * 10);
		i++;
	}
	if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
		return(0);
	if (num * sign == previous && index != 1)
		return(0);
	previous = num * sign;
	return(1);
}

int	ft_strtoint(char *str)
{
	int	sign;
	int	i;
	int num;

	sign = 1;
	i = 0;
	num = 0;
	if(str[i] == '-')
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