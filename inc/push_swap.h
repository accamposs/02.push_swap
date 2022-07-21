/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catperei <catperei@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:52:38 by catperei          #+#    #+#             */
/*   Updated: 2022/07/05 11:51:02 by catperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# include <stdio.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

// STRUCTS

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_costs
{
	int		a;
	int		b;
}	t_costs;

/*
** SET UP
*/

int			ft_check_duplicates(char **argv);
int			ft_argcheck(char **argv);

/*
** STACK FUNCTIONS
*/

void		ft_swap(t_stack **stc);
void		ft_push(t_stack **send, t_stack **receiv);
void		ft_rotate(t_stack **stc);
void		ft_rev_rotate(t_stack **stc);
t_stack		*ft_stcnewnode(int num);
void		ft_stcadd_back(t_stack **stc, t_stack *new);
void		ft_stcadd_front(t_stack **stc, t_stack *new);
int			ft_stcsize(t_stack **stc);
void		ft_stcprint(t_stack **st);
void		ft_ex_op_s(t_stack **s_a, t_stack **s_b, const char *op, char **c);
void		ft_ex_op_p(t_stack **s_a, t_stack **s_b, const char *op, char **c);
void		ft_ex_op_r(t_stack **s_a, t_stack **s_b, const char *op, char **c);
void		ft_ex_op_rr(t_stack **s_a, t_stack **s_b, const char *op, char **c);

/*
** SORTING
*/

int			ft_is_sorted(t_stack **stc);
void		ft_sort3(t_stack**s_a, t_stack **s__b, char **comms);
void		ft_sortmore(t_stack **s_a, t_stack **s_b, char **comms);
int			get_max_el(t_stack **s_a);
int			get_min_el(t_stack **s_a);
int			get_min_index(t_stack **s_a);
int			get_max(int a, int b);
int			get_min(int a, int b);
void		ft_calc_costs_b(int *cost_b, int len);
int			find_best_index_a(t_stack **s_a, t_stack *tmp1);
void		ft_calc_costs_a(t_stack **s_a, t_stack **s_b, int *cost_a);
int			ft_find_best_index(int *cost_tot, int len);
int			refactor_index(int best_index, int len);

#endif
