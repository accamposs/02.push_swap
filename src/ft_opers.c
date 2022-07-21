/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catperei <catperei@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:11:17 by catperei          #+#    #+#             */
/*   Updated: 2022/06/29 01:58:18 by catperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_swap(t_stack **stc)
{
	t_stack	*curr_head;
	t_stack	*new_head;

	if (ft_stcsize(stc) == 0 || ft_stcsize(stc) == 1)
		return ;
	curr_head = *stc;
	new_head = (*stc)->next;
	curr_head->next = new_head->next;
	new_head->next = curr_head;
	*stc = new_head;
}

void	ft_push(t_stack **send, t_stack **receive)
{
	t_stack	*new_head;
	t_stack	*sent_head;

	if (ft_stcsize(send) == 0)
		return ;
	new_head = (*send)->next;
	sent_head = *send;
	(*send) = new_head;
	ft_stcadd_front(receive, sent_head);
}

void	ft_rotate(t_stack **stc)
{
	t_stack	*curr_head;
	t_stack	*tmp;

	if ((ft_stcsize(stc) == 0 || ft_stcsize(stc) == 1))
		return ;
	curr_head = *stc;
	*stc = (*stc)->next;
	tmp = *stc;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = curr_head;
	curr_head->next = NULL;
}

void	ft_rev_rotate(t_stack **stc)
{
	t_stack		*curr_head;
	t_stack		*new_head;
	t_stack		*tmp;

	if (ft_stcsize(stc) == 0 || ft_stcsize(stc) == 1)
		return ;
	curr_head = *stc;
	tmp = *stc;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_head = tmp;
	*stc = new_head;
	new_head->next = curr_head;
	while (tmp->next != new_head)
		tmp = tmp->next;
	tmp->next = NULL;
}
