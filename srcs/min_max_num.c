/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:50:06 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/21 16:52:41 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_num(t_push_swap *ps)
{
	t_listps	*tmp;
	int			min_num;
	int			check;

	min_num = ps->stack_b->num;
	check = 1;
	while (check == 1)
	{
		tmp = ps->stack_b;
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

int	get_max_num(t_push_swap *ps)
{
	t_listps	*tmp;
	int			max_num;
	int			check;

	max_num = ps->stack_b->num;
	check = 1;
	while (check == 1)
	{
		tmp = ps->stack_b;
		while (tmp)
		{
			if (tmp->num > max_num)
			{
				max_num = tmp->num;
				check = 1;
			}
			tmp = tmp->next;
			check = 0;
		}
	}
	return (max_num);
}	