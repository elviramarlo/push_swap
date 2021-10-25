/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:50:06 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/24 19:21:28 by elvmarti         ###   ########.fr       */
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

int	get_mid(t_push_swap *ps)
{
	int size = ft_lstsize_ps(ps->stack_a) / 2;
	int i = 0;
	t_listps *tmp;

	tmp = ps->stack_a_copy;
	while (i < size)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->num);
}

void	sort_copy(t_push_swap *ps)
{
	t_listps *tmp;
	int aux;
	int check = 1;

	while (check == 1)
	{
		tmp = ps->stack_a_copy;
		check = 0;
		while (tmp->next)
		{
			if (tmp->num > tmp->next->num)
			{
				aux = tmp->num;
				tmp->num = tmp->next->num;
				tmp->next->num = aux;
				check = 1;
			}
			tmp = tmp->next;
		}
	}
}