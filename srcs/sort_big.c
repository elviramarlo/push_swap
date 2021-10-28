/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:51:57 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/28 18:20:40 by elvmarti         ###   ########.fr       */
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

void	sort_onehundred(t_push_swap *ps, int size)
{
	int	i;
	int	num;

	i = 0;
	num = 20;
	while (i < size)
	{
		while (i < num && ps->stack_a)
		{
			chunks(ps, num);
			i++;
		}
		if (num < size)
			num += 20;
	}
}

void	sort_fivehundred(t_push_swap *ps, int size)
{
	int	i;
	int	num;

	i = 0;
	num = 50;
	while (i < size)
	{
		while (i < num && ps->stack_a)
		{
			chunks(ps, num);
			i++;
		}
		if (num < size)
			num += 50;
	}
}

void	sort_big_stack(t_push_swap *ps, int size)
{
	if (size <= 100)
		sort_onehundred(ps, size);
	else if (size > 100)
		sort_fivehundred(ps, size);
	while (ft_lstsize_ps(ps->stack_b))
		sort_all(ps, ft_lstsize_ps(ps->stack_b));
}
