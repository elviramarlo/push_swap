/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:51:57 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/29 17:50:50 by elvmarti         ###   ########.fr       */
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
			rule_rx(&ps, &ps->stack_b, 'b');
		else
			rule_rrx(&ps, &ps->stack_b, 'b');
	}
	rule_pa(&ps);
}

static void	sort_chunks(t_push_swap *ps, int size, int num)
{
	int	i;
	int	temp;

	i = 0;
	temp = num;
	while (i < size)
	{
		while (i < num && ps->stack_a)
		{
			chunks(ps, num);
			i++;
		}
		if (num < size)
			num = num + temp;
	}
}

void	sort_big_stack(t_push_swap *ps, int size)
{
	if (size <= 100)
		sort_chunks(ps, size, 20);
	else if (size > 100)
		sort_chunks(ps, size, 50);
	while (ft_lstsize_ps(ps->stack_b))
		sort_all(ps, ft_lstsize_ps(ps->stack_b));
}
