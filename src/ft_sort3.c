/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catperei <catperei@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:27:19 by catperei          #+#    #+#             */
/*   Updated: 2022/06/29 02:04:59 by catperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort3(t_stack **s_a, t_stack **s_b, char **comms)
{
	int	first;
	int	second;
	int	third;

	first = (*s_a)->num;
	second = (*s_a)->next->num;
	third = (*s_a)->next->next->num;
	if (ft_stcsize(s_a) == 2 && !ft_is_sorted(s_a))
		ft_ex_op_s(s_a, s_b, "sa", comms);
	else if (first < second && second > third && first < third)
	{
		ft_ex_op_rr(s_a, s_b, "rra", comms);
		ft_ex_op_s(s_a, s_b, "sa", comms);
	}
	else if (first > second && second < third && first < third)
		ft_ex_op_s(s_a, s_b, "sa", comms);
	else if (first < second && second > third && first > third)
		ft_ex_op_rr(s_a, s_b, "rra", comms);
	else if (first > second && second < third && first > third)
		ft_ex_op_r(s_a, s_b, "ra", comms);
	else if (first > second && second > third && third < first)
	{
		ft_ex_op_s(s_a, s_b, "sa", comms);
		ft_ex_op_rr(s_a, s_b, "rra", comms);
	}
}
