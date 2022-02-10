/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:29:31 by elvmarti          #+#    #+#             */
/*   Updated: 2022/02/10 17:04:43 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	hold_first(t_push_swap *ps, int num, t_listps *tmp, t_listps *tmp2)
{
	int	i_copy;

	ps->i = 0;
	ps->check = 0;
	while (tmp)
	{
		tmp2 = ps->stack_a_copy;
		i_copy = 0;
		while (i_copy < num && num < ft_lstsize_ps(ps->stack_a_copy) + 1)
		{
			if (tmp->num == tmp2->num)
			{
				ps->hold_first = tmp->num;
				ps->pos_first = ps->i;
				ps->check = 1;
				break ;
			}
			tmp2 = tmp2->next;
			i_copy++;
		}
		if (ps->check == 1)
			break ;
		tmp = tmp->next;
		ps->i++;
	}
}

static void	hold_second(t_push_swap *ps, int num, t_listps *tmp, t_listps *tmp2)
{
	int	i;
	int	i_copy;

	i = 0;
	tmp = ps->stack_a;
	while (tmp)
	{
		tmp2 = ps->stack_a_copy;
		i_copy = 0;
		while (i_copy < num && num < ft_lstsize_ps(ps->stack_a_copy) + 1)
		{
			if (tmp->num == tmp2->num)
			{
				ps->hold_second = tmp->num;
				ps->pos_second = i;
			}
			tmp2 = tmp2->next;
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

	tmp = ps->stack_a;
	tmp_copy = ps->stack_a_copy;
	hold_first(ps, num, tmp, tmp_copy);
	hold_second(ps, num, tmp, tmp_copy);
	ps->i = 0;
	if (ps->pos_first <= ps->pos_second)
	{
		while (ps->i < ps->pos_first)
		{
			rule_rx(&ps, &ps->stack_a, 'a');
			ps->i++;
		}
	}
	else
	{
		while (ps->i < ps->pos_second)
		{
			rule_rrx(&ps, &ps->stack_a, 'a');
			ps->i++;
		}
	}
	rule_pb(&ps);
}
