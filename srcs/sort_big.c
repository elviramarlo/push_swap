/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:51:57 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/25 15:46:27 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_all(t_push_swap *ps, int size)
{
	t_listps	*tmp;
	int			i;
	int			max_num;

	max_num = get_max_num(ps->stack_b);
	tmp = ps->stack_b;
	i = 0;
	while (tmp->next)
	{
		if (tmp->num == max_num)
			break ;
		tmp = tmp->next;
		i++;
	}
	while (ps->stack_b->num != max_num)
	{
		if (i < size / 2)
			rule_rb(&ps);
		else
			rule_rrb(&ps);
	}
	rule_pa(&ps);
}

void	chunks(t_push_swap *ps, int num)
{
	t_listps	*tmp;
	t_listps	*tmp_copy;
	int			i;
	int			i_copy;
	int			check;

	tmp = ps->stack_a;
	i = 0;
	check = 0;
	while (tmp)
	{
		tmp_copy = ps->stack_a_copy;
		i_copy = 0;
		while (i_copy < num && num < ft_lstsize_ps(ps->stack_a_copy) + 1)
		{
			if (tmp->num == tmp_copy->num)
			{
				ps->hold_first = tmp->num;
				check = 1;
				ps->pos_first = i;
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
	i = 0;
	if (ps->pos_first <= ps->pos_second)
	{
		while (i < ps->pos_first)
		{
			rule_ra(&ps);
			i++;
		}
		rule_pb(&ps);
	}
	else
	{
		while (i < ps->pos_second)
		{
			rule_rra(&ps);
			i++;
		}
		rule_pb(&ps);
	}
}

void	sort_onehundred(t_push_swap *ps, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i < 20 && ps->stack_a)
			chunks(ps, 20);
		else if (i < 40 && ps->stack_a)
			chunks(ps, 40);
		else if (i < 60 && ps->stack_a)
			chunks(ps, 60);
		else if (i < 80 && ps->stack_a)
			chunks(ps, 80);
		else if (i < 100 && ps->stack_a)
			chunks(ps, 100);
		i++;
	}
	while (ft_lstsize_ps(ps->stack_b))
		sort_all(ps, ft_lstsize_ps(ps->stack_b));
}

void	sort_fivehundred(t_push_swap *ps, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i < 50 && ps->stack_a)
			chunks(ps, 50);
		else if (i < 100 && ps->stack_a)
			chunks(ps, 100);
		else if (i < 150 && ps->stack_a)
			chunks(ps, 150);
		else if (i < 200 && ps->stack_a)
			chunks(ps, 200);
		else if (i < 250 && ps->stack_a)
			chunks(ps, 250);
		else if (i < 300 && ps->stack_a)
			chunks(ps, 300);
		else if (i < 350 && ps->stack_a)
			chunks(ps, 350);
		else if (i < 400 && ps->stack_a)
			chunks(ps, 400);
		else if (i < 450 && ps->stack_a)
			chunks(ps, 450);
		else if (i < 500 && ps->stack_a)
			chunks(ps, 500);
		i++;
	}
	while (ft_lstsize_ps(ps->stack_b))
		sort_all(ps, ft_lstsize_ps(ps->stack_b));
}
