/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rrx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:19:07 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/28 18:18:40 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rule_rra(t_push_swap **ps)
{
	t_listps	*lst;
	t_listps	*tmp;
	int			i;
	int			size;

	size = ft_lstsize_ps((*ps)->stack_a) - 1;
	(*ps)->num_mov++;
	i = 1;
	if (size > 0)
	{
		lst = (*ps)->stack_a;
		while (i < size)
		{
			lst = lst->next;
			i++;
		}
		tmp = lst;
		while (lst->next)
			lst = lst->next;
		lst->next = (*ps)->stack_a;
		(*ps)->stack_a = tmp->next;
		tmp->next = NULL;
	}
	print_str("rra");
}

void	rule_rrb(t_push_swap **ps)
{
	t_listps	*lst;
	t_listps	*tmp;
	int			i;
	int			size;

	size = ft_lstsize_ps((*ps)->stack_b) - 1;
	(*ps)->num_mov++;
	i = 1;
	if (size > 0)
	{
		lst = (*ps)->stack_b;
		while (i < size)
		{
			lst = lst->next;
			i++;
		}
		tmp = lst;
		while (lst->next)
			lst = lst->next;
		lst->next = (*ps)->stack_b;
		(*ps)->stack_b = tmp->next;
		tmp->next = NULL;
	}
	print_str("rrb");
}

void	rule_rrr(t_push_swap **ps)
{
	(*ps)->num_mov--;
	rule_rra(ps);
	rule_rrb(ps);
}
