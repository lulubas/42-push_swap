/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:49:50 by lbastien          #+#    #+#             */
/*   Updated: 2023/01/23 19:16:50 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<unistd.h>
# include<stdarg.h>
# include<stdlib.h>
# include<stdio.h>

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}					t_list;

typedef struct st_int
{
	int				num;
	struct st_int	*next;
}					t_int;

//Main functions
t_int	*ft_parse_input(int argc, char **argv);
int		ft_init(int argc, char **argv);
int		ft_checks(char *str, t_int *list);
int		ft_duplicate(int num, t_int *list);
void	ft_sort(t_int **stacka, t_int **stackb, int argc);
void	ft_smallsort(t_int **stacka, t_int **stackb, int argc);
void	ft_minisort(t_int **stacka);
void	ft_minisort_rev(t_int **stackb);
void	ft_mediumsort(t_int **stacka, t_int **stackb, int argc);
int		ft_split(t_int **stacka, t_int **stackb, int len);
void	ft_insertsort(t_int **stacka, t_int **stackb);
int		ft_find_median(t_int *stack, int len);
int		ft_partition(int *array, int beg, int end);
void	ft_qsort(int *array, int beg, int end);
void	ft_swap(int *a, int	*b);
void	ft_insert(t_int **stackb);
int		ft_find_index(t_int *stack);
t_int	*ft_pivot(t_int *head, t_int *tail);
t_int	*ft_quicksort(t_int *stack);
void	ft_bigsort(t_int **stacka, t_int **stackb);
int		ft_sort_a(t_int **stacka, t_int **stackb, \
			int sorted, t_int **partition_b);
void	ft_sort_b(t_int **stacka, t_int **stackb, t_int **partition_b);
void	ft_nanosort_a(t_int **stacka, int sorted);
void	ft_nanosort_b(t_int **stacka, t_int **stackb, t_int **partition_b);
int		ft_split_a(t_int **stacka, t_int **stackb, int len);
int		ft_split_b(t_int **stacka, t_int **stackb, int len);
void	ft_return_a_to_start(t_int **stacka, int count_ra);
void	ft_return_b_to_start(t_int **stackb, int count_rb);

//Operations functions
void	do_pa(t_int **stacka, t_int **stackb, int num);
void	do_pb(t_int **stacka, t_int **stackb);
void	do_sa(t_int **stacka);
void	do_sb(t_int **stackb);
void	do_ra(t_int **stacka, int num);
void	do_rb(t_int **stackb, int num);
void	do_rra(t_int **stacka, int num);
void	do_rrb(t_int **stackb, int num);
void	ft_freetop(t_int **stack);
void	ft_freebottom(t_int *stack);
void	free_list(t_int *list);
void	free_node(t_int *node);

//Utilities functions
void	ft_print_lst(t_int *list);
void	ft_print_stacks(t_int *stacka, t_int *stackb);
int		ft_check_sorted(t_int *stack, int len);
int		ft_check_sorted_rev(t_int *stack, int len);
int		ft_strtoint(char *str);

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
void	ft_intlst_addback(t_int **lst, t_int *new);
t_int	*ft_intlst_new(int num);
t_int	*ft_intlst_last(t_int *lst);
void	ft_intlst_addfront(t_int **lst, t_int *new);
int		ft_intlst_size(t_int *lst);

#endif
