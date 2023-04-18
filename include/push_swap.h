/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:49:50 by lbastien          #+#    #+#             */
/*   Updated: 2023/01/23 19:16:50 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>
# include<stdlib.h>
# include<stdio.h>

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}					t_list;

typedef struct sint_list
{
	int					num;
	struct sint_list	*next;
}					int_list;

//Local functions

int			ft_init(int argc, char **argv);
int			ft_checks(char *str, int index);
void		ft_print_lst(int_list *list);
void		ft_print_stacks(int_list *stacka, int_list *stackb);
int			ft_check_sorted(int_list *stack);

int			ft_strtoint(char *str);
void		ft_intlst_addback(int_list **lst, int_list *new);
int_list	*ft_intlst_new(int num);
int_list	*ft_intlst_last(int_list *lst);
int_list	*ft_parse_input(int argc, char **argv);
void		ft_intlst_addfront(int_list **lst, int_list *new);

void		do_pa(int_list **stacka, int_list **stackb);
void		do_pb(int_list **stacka, int_list **stackb);
void		do_sb(int_list **stackb);
void		do_rb(int_list **stackb);
void		do_rrb(int_list **stackb);

int_list	*ft_pivot(int_list *head, int_list *tail);
int_list	*ft_quicksort(int_list *stack);
void 		ft_insertsort(int_list **stacka, int_list **stackb);
void 		ft_insert(int_list **stackb);
int			ft_find_index(int_list *stack);
void		ft_freetop(int_list **stack);
void 		ft_freebottom(int_list *stack);





//Libft functions

int		ft_printf(const char *str, ...);
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
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_isdigit(int a);

#endif