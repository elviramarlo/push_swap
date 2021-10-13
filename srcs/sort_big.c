/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:51:57 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/13 19:26:20 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_onehundred(t_push_swap *ps , int size)
{
	t_listps *tmp;
	int i = 0;
	int min_num;
	int check = 1;

	min_num = ps->stack_a->num;
	while (check == 1)
	{
		tmp = ps->stack_a;
		check = 0;
		while (tmp)
		{
			if (tmp->num < min_num)
			{
				min_num = tmp->num;
				check = 1;
			}
			tmp = tmp->next;
		}
	}
	printf("\nMIN NUM: %d\n", min_num);
	tmp = ps->stack_a;
	while (tmp->next)
	{
		if (tmp->num == min_num)
			break;
		tmp = tmp->next;
		i++;
	}
	//printf("AAAA %d", size);
	if (i < size / 2)
	{
		while (i > 0)
		{
			rule_ra(&ps);
			i--;
		}
		rule_pb(&ps);
	}
	else if (i >= size / 2)
	{
		i = size - i;
		while (i > 0)
		{
			rule_rra(&ps);
			i--;
		}
		rule_pb(&ps);
	}
	//size++;
}

void	sort_big_stack(t_push_swap *ps, int size)
{
	if (size <= 100)
	{
		while (ps->stack_a->next)
			sort_onehundred(ps , size);
	}
}