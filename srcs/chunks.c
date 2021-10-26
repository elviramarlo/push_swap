/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:29:31 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/26 17:31:06 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	hold_first(t_push_swap *ps, int num, t_listps *tmp, t_listps *tmp_copy)
{
	int i;
	int i_copy;
	int check = 0;

	i = 0;
	while (tmp)
	{
		tmp_copy = ps->stack_a_copy;
		i_copy = 0;
		while (i_copy < num && num < ft_lstsize_ps(ps->stack_a_copy) + 1)
		{
			if (tmp->num == tmp_copy->num)
			{
				ps->hold_first = tmp->num;
				ps->pos_first = i;
				check = 1;
				break ;
			}
			tmp_copy = tmp_copy->next;
			i_copy++;
		}
		if (check == 1)
			break ;
		tmp = tmp->next;
		i++;
	}
}

static void	hold_second(t_push_swap *ps, int num, t_listps *tmp, t_listps *tmp_copy)
{
	int i;
	int i_copy;
	
	i = 0;
	tmp = ps->stack_a;
	while (tmp)
	{
		tmp_copy = ps->stack_a_copy;
		i_copy = 0;
		while (i_copy < num && num < ft_lstsize_ps(ps->stack_a_copy) + 1)
		{
			if (tmp->num == tmp_copy->num)
			{
				ps->hold_second = tmp->num;
				ps->pos_second = i;
			}
			tmp_copy = tmp_copy->next;
			i_copy++;
		}
		tmp = tmp->next;
		i++;
	}
	ps->pos_second = ft_lstsize_ps(ps->stack_a) - ps->pos_second;
}

void	chunks(t_push_swap *ps, int num)
{
	t_listps	*tmp;
	t_listps	*tmp_copy;
	int			i;

	tmp = ps->stack_a;
	tmp_copy = ps->stack_a_copy;
	hold_first(ps, num, tmp, tmp_copy);
	hold_second(ps, num, tmp, tmp_copy);
	i = 0;
	if (ps->pos_first <= ps->pos_second)
	{
		while (i < ps->pos_first)
		{
			rule_ra(&ps);
			i++;
		}
	}
	else
	{
		while (i < ps->pos_second)
		{
			rule_rra(&ps);
			i++;
		}
	}
		rule_pb(&ps);
}
