/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catperei <catperei@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 02:16:48 by catperei          #+#    #+#             */
/*   Updated: 2022/07/08 13:07:10 by catperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stcnewnode(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

void	ft_stcadd_back(t_stack **stc, t_stack *new)
{
	t_stack	*tmp;

	if (stc)
	{
		if (*stc == NULL)
			*stc = new;
		else
		{
			tmp = *stc;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void	ft_stcadd_front(t_stack **stc, t_stack *new)
{
	if (stc && new)
	{
		new->next = *stc;
		*stc = new;
	}
}

int	ft_stcsize(t_stack **stc)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = *stc;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	ft_stcprint(t_stack **stc)
{
	t_stack	*tmp;

	if (!(*stc))
		return ;
	tmp = *stc;
	ft_printf("-----\n");
	while (tmp != NULL)
	{
		ft_printf("current node %p is: %d\n", tmp, (tmp)->num);
		tmp = (tmp)->next;
	}
	ft_printf("-----\n");
}
