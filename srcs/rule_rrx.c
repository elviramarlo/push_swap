/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rrx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:19:07 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/05 23:00:22 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rule_rra(t_push_swap **ps)
{
	t_listps *lst;
	int i = 1;

	(*ps)->num_mov++;
	lst = ft_lstlast_ps((*ps)->stack_a);
	ft_lstadd_front_ps(&(*ps)->stack_a, ft_lstnew_ps(lst->num));
	lst = (*ps)->stack_a;
	while(lst != NULL && i < ft_lstsize_ps(lst) - 1)
	{
		lst = lst->next;
	}
	lst->next = NULL;
	ft_lstdelone_ps(lst);
}

void	rule_rrb(t_push_swap **ps)
{
	t_listps *lst;
	int i = 1;

	(*ps)->num_mov++;
	lst = ft_lstlast_ps((*ps)->stack_b);
	ft_lstadd_front_ps(&(*ps)->stack_b, ft_lstnew_ps(lst->num));
	lst = (*ps)->stack_b;
	while(lst != NULL && i < ft_lstsize_ps(lst) - 1)
	{
		lst = lst->next;
	}
	lst->next = NULL;
	ft_lstdelone_ps(lst);
}

void	rule_rrr(t_push_swap **ps)
{
	rule_rra(ps);
	rule_rrb(ps);
}