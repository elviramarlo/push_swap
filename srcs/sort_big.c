/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:51:57 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/14 16:32:17 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_num(t_push_swap *ps)
{
	t_listps	*tmp;
	int			min_num;
	int			check;

	min_num = ps->stack_a->num;
	check = 1;
	while (check == 1)
	{
		tmp = ps->stack_a;
		while (tmp)
		{
			if (tmp->num < min_num)
			{
				min_num = tmp->num;
				check = 1;
			}
			tmp = tmp->next;
			check = 0;
		}
	}
	return (min_num);
}	

static void	sort_onehundred(t_push_swap *ps , int size)
{
	t_listps *tmp;
	int i;
	int min_num;
	
	min_num = get_min_num(ps);
	//printf("\nMIN NUM: %d\n", min_num);
	tmp = ps->stack_a;
	i = 0;
	while (tmp->next)
	{
		if (tmp->num == min_num)
			break;
		tmp = tmp->next;
		i++;
	}
	//printf("AAAA %d", size);
	while (ps->stack_a->num != min_num)
	{
		if (i < size / 2)
			rule_ra(&ps);
		else
			rule_rra(&ps);
	}
	rule_pb(&ps);
}

void	sort_big_stack(t_push_swap *ps, int size)
{
	if (size <= 100)
	{
		while (ps->stack_a->next)
			sort_onehundred(ps , size);
		while (ps->stack_b)
			rule_pa(&ps);
	}
}