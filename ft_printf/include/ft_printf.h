/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:49:50 by lbastien          #+#    #+#             */
/*   Updated: 2023/01/23 18:50:38 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>
# include<stdlib.h>

int		ft_parse(const char c, va_list args);
int		ft_printf(const char *input, ...);
int		ft_putstr(const	char *str);
int		ft_putnbr(int num);
int		ft_putunbr(unsigned int num);
int		ft_putchar(char c);
char	*ft_itoa(int m);
char	*ft_uitoa(unsigned int m);
int		ft_ucount(long unsigned int n);
int		ft_puthex(unsigned long num, char c);
int		ft_counthex(unsigned long num);
int		ft_modulohex(unsigned long n);
char	*ft_iterate(char *str, char c);
int		ft_toupper(int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
