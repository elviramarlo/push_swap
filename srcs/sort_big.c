/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_mal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:51:57 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/24 19:20:02 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_onehundred(t_push_swap *ps , int size)
{
	t_listps *tmp;
	int i;
	int max_num;
	
	max_num = get_max_num(ps);
	tmp = ps->stack_b;
	i = 0;
	while (tmp->next)
	{
		if (tmp->num == max_num)
			break;
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
	int			i = 0;
	int			i_copy;
	int			check = 0;
	
	tmp = ps->stack_a;
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

void	sort_big_stack(t_push_swap *ps, int size)
{
	int	i;

	i = 0; 
	if (size <= 100)
	{
		sort_copy(ps);
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
		//printf("QUEPASA %d", ft_lstsize_ps(ps->stack_a));
		while (ft_lstsize_ps(ps->stack_b))
			sort_onehundred(ps, ft_lstsize_ps(ps->stack_b));
	}
}
