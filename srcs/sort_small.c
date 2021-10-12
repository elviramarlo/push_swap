/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:12:23 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/12 17:37:53 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_push_swap *ps)
{
	int	one;
	int	two;
	int	three;

	one = ps->stack_a->num;
	two = ps->stack_a->next->num;
	three = ps->stack_a->next->next->num;
	if (one > two && two < three && one < three) //2 1 3
		rule_sa(ps);
	else if (one > two && two < three && one > three) //3 1 2
		rule_ra(&ps);
	else if (one < two && two > three && one < three) //1 3 2
	{
		rule_sa(ps);
		rule_ra(&ps);
	}
	else if (one > two && two > three && one > three) //3 2 1
	{
		rule_ra(&ps);
		rule_sa(ps);
	}
	else if (one < two && two > three && one > three) //2 3 1
		rule_rra(&ps);
}

static void	sort_four(t_push_swap *ps, int size)
{
	while(size > 3)
	{
		int pos1 = ps->stack_a->num;
		int pos2 = ps->stack_a->next->num;
		int pos3 = ps->stack_a->next->next->num;
		int pos4 = ps->stack_a->next->next->next->num;

		if (pos1 < pos2 && pos1 < pos3 && pos1 < pos4)
		{
			rule_pb(&ps);
			size--;
		}
		else if (pos1 > pos2)
			rule_sa(ps);
		else if (pos1 > pos3)
		{
			rule_ra(&ps);
			rule_ra(&ps);
		}
		else if (pos1 > pos4)
		{
			rule_rra(&ps);
			rule_rra(&ps);
		}
	}
	sort_three(ps);
	rule_pa(&ps);
	rule_pa(&ps);
}

static void	sort_five(t_push_swap *ps, int size)
{
	while (size > 4)  
	{
		int pos1 = ps->stack_a->num;
		int pos2 = ps->stack_a->next->num;
		int pos3 = ps->stack_a->next->next->num;
		int pos4 = ps->stack_a->next->next->next->num;
		int pos5 = ps->stack_a->next->next->next->next->num;

		if (pos1 < pos2 && pos1 < pos3 && pos1 < pos4 && pos1 < pos5)
		{
			rule_pb(&ps);
			size--;
		}
		else if (pos1 > pos2)
			rule_sa(ps);
		else if (pos1 > pos3)
		{
			rule_ra(&ps);
			rule_ra(&ps);
		}
		else if (pos1 > pos4)
		{
			rule_rra(&ps);
			rule_rra(&ps);
		}
		else if (pos1 > pos5)
			rule_rra(&ps);
	}
	sort_four(ps, size);
	
}

void	sort_small_stack(t_push_swap *ps)
{
	int			size;

	size =  ft_lstsize_ps(ps->stack_a);
	if (size == 2)
		rule_sa(ps);
	if (size == 3)
		sort_three(ps);
	if (size == 4)
		sort_four(ps, size);
	if (size == 5)
		sort_five(ps, size);
}
