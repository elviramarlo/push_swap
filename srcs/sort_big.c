/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:51:57 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/21 17:09:16 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_onehundred(t_push_swap *ps , int size)
{
	t_listps *tmp;
	int i;
	int max_num;
	
	max_num = get_max_num(ps);
	//printf("\nMIN NUM: %d\n", min_num);
	tmp = ps->stack_b;
	i = 0;
	while (tmp->next)
	{
		if (tmp->num == max_num)
			break;
		tmp = tmp->next;
		i++;
	}
	//printf("AAAA %d", size);
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
		while (i_copy < num)
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
	printf("HOLD FIRST: %d\n", ps->hold_first);
	printf("POS: %d\n", ps->pos_first);

	i = 0;
	tmp = ps->stack_a;
	while (tmp)
	{
		tmp_copy = ps->stack_a_copy;
		i_copy = 0;
		while (i_copy < num)
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
	printf("HOLD SECOND: %d\n", ps->hold_second);
	//printf("POS: %d\n", ps->pos_second);
	ps->pos_second = ft_lstsize_ps(ps->stack_a) - ps->pos_second;
	printf("POS: %d\n", ps->pos_second);
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

void	sort_big_stack(t_push_swap *ps, int size)
{
	int	i;

	i = 0; 
	if (size <= 100)
	{
		sort_copy(ps);
		while (i < 20)
		{
			chunks(ps, 20);
			i++;
		}
		while (i < 40)
		{
			chunks(ps, 40);
			i++;
		}
			while (i < 60)
		{
			chunks(ps, 60);
			i++;
		}
			while (i < 80)
		{
			chunks(ps, 80);
			i++;
		}
			while (i < 100)
		{
			chunks(ps, 100);
			i++;
		}
		i = 0;
		while (i < 100)
		{
			sort_onehundred(ps, 100);
			i++;
		}
	}
}
