/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_sx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:50:44 by elvmarti          #+#    #+#             */
/*   Updated: 2022/02/10 17:05:22 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rule_sx(t_push_swap *ps, t_listps *list, char c)
{	
	int	tmp;

	ps->num_mov++;
	if (ft_lstsize_ps(list) >= 2)
	{
		tmp = list->num;
		list->num = list->next->num;
		list->next->num = tmp;
	}
	if (c == 'a')
		print_str("sa");
	else
		print_str("sb");
}

void	rule_ss(t_push_swap *ps)
{	
	ps->num_mov--;
	rule_sx(ps, ps->stack_a, 'a');
	rule_sx(ps, ps->stack_a, 'b');
}
