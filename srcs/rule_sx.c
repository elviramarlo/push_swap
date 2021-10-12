/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_sx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:50:44 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/12 19:44:18 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rule_sa(t_push_swap *ps)
{	
	int tmp;

	ps->num_mov++;
	if (ft_lstsize_ps(ps->stack_a) >= 2)
	{
		tmp = ps->stack_a->num;
		ps->stack_a->num = ps->stack_a->next->num;
		ps->stack_a->next->num = tmp;
	}
	/* printf("tmp: %d", tmp);
	printf("pos dos: %d", ps->stack_a->next->num);
	printf("pos uno: %d", ps->stack_a->num);*/
}

void	rule_sb(t_push_swap *ps)
{	
	int tmp;

	ps->num_mov++;
	if (ft_lstsize_ps(ps->stack_a) >= 2)
	{
		tmp = ps->stack_b->num;
		ps->stack_b->num = ps->stack_b->next->num;
		ps->stack_b->next->num = tmp;
	}
}

void	rule_ss(t_push_swap *ps)
{	
	ps->num_mov--;
	rule_sa(ps);
	rule_sb(ps);
	
}