/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:12:23 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/29 17:41:26 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_push_swap *ps)
{
	int	one;
	int	two;
	int	three;

	one = ps->stack_a->num;
	two = ps->stack_a->next->num;
	three = ps->stack_a->next->next->num;
	if (one > two && two < three && one < three)
		rule_sx(ps, ps->stack_a, 'a');
	else if (one > two && two < three && one > three)
		rule_rx(&ps, &ps->stack_a, 'a');
	else if (one < two && two > three && one < three)
	{
		rule_sx(ps, ps->stack_a, 'a');
		rule_rx(&ps, &ps->stack_a, 'a');
	}
	else if (one > two && two > three && one > three)
	{
		rule_rx(&ps, &ps->stack_a, 'a');
		rule_sx(ps, ps->stack_a, 'a');
	}
	else if (one < two && two > three && one > three)
		rule_rrx(&ps, &ps->stack_a, 'a');
}

void	sort_four(t_push_swap *ps, int size)
{
	t_listps	*tmp;
	int			min_num;
	int			i;

	min_num = get_min_num(ps->stack_a);
	tmp = ps->stack_a;
	i = 0;
	while (tmp->next)
	{
		if (tmp->num == min_num)
			break ;
		tmp = tmp->next;
		i++;
	}
	while (ps->stack_a->num != min_num)
	{
		if (i < size / 2)
			rule_rx(&ps, &ps->stack_a, 'a');
		else
			rule_rrx(&ps, &ps->stack_a, 'a');
	}
	rule_pb(&ps);
	sort_three(ps);
	rule_pa(&ps);
}

void	sort_five(t_push_swap *ps, int size)
{
	t_listps	*tmp;
	int			min_num;
	int			i;

	min_num = get_min_num(ps->stack_a);
	tmp = ps->stack_a;
	i = 0;
	while (tmp->next)
	{
		if (tmp->num == min_num)
			break ;
		tmp = tmp->next;
		i++;
	}
	while (ps->stack_a->num != min_num)
	{
		if (i < size)
			rule_rx(&ps, &ps->stack_a, 'a');
		else
			rule_rrx(&ps, &ps->stack_a, 'a');
	}
	rule_pb(&ps);
	sort_four(ps, size);
	rule_pa(&ps);
}

void	sort_small_stack(t_push_swap *ps, int size)
{
	if (size == 2)
		rule_sx(ps, ps->stack_a, 'a');
	if (size == 3)
		sort_three(ps);
	if (size == 4)
		sort_four(ps, size);
	if (size == 5)
		sort_five(ps, size);
}
