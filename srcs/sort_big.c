/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:51:57 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/20 16:59:48 by elvmarti         ###   ########.fr       */
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

/* static void	sort_onehundred(t_push_swap *ps , int size)
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
} */
void	chunks(t_push_swap *ps)
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
		while (i_copy < 20)
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
		while (i_copy < 20)
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
	printf("POS: %d\n", ps->pos_second);
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
	if (size <= 100)
	{
		/* while (ps->stack_a->next)
			sort_onehundred(ps , size);
		while (ps->stack_b)
			rule_pa(&ps); */
		sort_copy(ps);
		chunks(ps);
	}
}
