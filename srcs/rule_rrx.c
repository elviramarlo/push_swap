/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rrx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:19:07 by elvmarti          #+#    #+#             */
/*   Updated: 2022/02/10 17:05:11 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rule_rrx(t_push_swap **ps, t_listps **list, char c)
{
	t_listps	*lst;
	t_listps	*tmp;
	int			i;

	(*ps)->num_mov++;
	i = 1;
	if (ft_lstsize_ps(*list) - 1 > 0)
	{
		lst = *list;
		while (i < ft_lstsize_ps(*list) - 1)
		{
			lst = lst->next;
			i++;
		}
		tmp = lst;
		while (lst->next)
			lst = lst->next;
		lst->next = *list;
		*list = tmp->next;
		tmp->next = NULL;
	}
	if (c == 'a')
		print_str("rra");
	else
		print_str("rrb");
}

void	rule_rrr(t_push_swap **ps)
{
	(*ps)->num_mov--;
	rule_rrx(ps, &(*ps)->stack_a, 'a');
	rule_rrx(ps, &(*ps)->stack_b, 'b');
}
