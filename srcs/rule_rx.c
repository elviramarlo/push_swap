/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:35:29 by elvmarti          #+#    #+#             */
/*   Updated: 2022/02/10 17:05:16 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rule_rx(t_push_swap **ps, t_listps **list, char c)
{
	int	tmp;

	(*ps)->num_mov++;
	tmp = 0;
	if (*list)
	{
		tmp = (*list)->num;
		ft_lstdelone_ps(*list);
		if (*list)
			*list = (*list)->next;
		else
			*list = NULL;
		ft_lstadd_back_ps(&(*list), ft_lstnew_ps(tmp));
	}
	if (c == 'a')
		print_str("ra");
	else
		print_str("rb");
}

void	rule_rr(t_push_swap **ps)
{
	(*ps)->num_mov--;
	rule_rx(ps, &(*ps)->stack_a, 'a');
	rule_rx(ps, &(*ps)->stack_b, 'b');
}
