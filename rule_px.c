/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:49:41 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/03 17:02:28 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rule_pb(t_push_swap **ps)
{
	(*ps)->num_mov++;
	if ((*ps)->stack_a)
	{
		ft_lstadd_front_ps(&(*ps)->stack_b, ft_lstnew_ps((*ps)->stack_a->num));
		ft_lstdelone_ps((*ps)->stack_a);
		if ((*ps)->stack_a)
			(*ps)->stack_a= (*ps)->stack_a->next;
		else
			(*ps)->stack_a = NULL;
	}
}

void rule_pa(t_push_swap **ps)
{
	(*ps)->num_mov++;
	if ((*ps)->stack_b)
	{
		ft_lstadd_front_ps(&(*ps)->stack_a, ft_lstnew_ps((*ps)->stack_b->num));
		ft_lstdelone_ps((*ps)->stack_b);
		if ((*ps)->stack_b->next)
			(*ps)->stack_b = (*ps)->stack_b->next;
		else
			(*ps)->stack_b = NULL;
	}
}