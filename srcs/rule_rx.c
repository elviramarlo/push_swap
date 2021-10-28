/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:35:29 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/28 18:19:20 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rule_ra(t_push_swap **ps)
{
	int	tmp;

	(*ps)->num_mov++;
	tmp = 0;
	if ((*ps)->stack_a)
	{
		tmp = (*ps)->stack_a->num;
		ft_lstdelone_ps((*ps)->stack_a);
		if ((*ps)->stack_a)
			(*ps)->stack_a = (*ps)->stack_a->next;
		else
			(*ps)->stack_a = NULL;
		ft_lstadd_back_ps(&(*ps)->stack_a, ft_lstnew_ps(tmp));
	}
	print_str("ra");
}

void	rule_rb(t_push_swap **ps)
{
	int	tmp;

	(*ps)->num_mov++;
	tmp = 0;
	if ((*ps)->stack_b)
	{
		tmp = (*ps)->stack_b->num;
		ft_lstdelone_ps((*ps)->stack_b);
		if ((*ps)->stack_b)
			(*ps)->stack_b = (*ps)->stack_b->next;
		else
			(*ps)->stack_b = NULL;
		ft_lstadd_back_ps(&(*ps)->stack_b, ft_lstnew_ps(tmp));
	}
	print_str("rb");
}

void	rule_rr(t_push_swap **ps)
{
	(*ps)->num_mov--;
	rule_ra(ps);
	rule_rb(ps);
}
