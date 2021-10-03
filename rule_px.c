/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:49:41 by elvmarti          #+#    #+#             */
/*   Updated: 2021/09/29 19:59:28 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rule_pa(t_push_swap *ps)
{
	int i;

	i = ft_lstsize_ps(ps->stack_a);
	ps->stack_b =  ft_lstnew_ps(ps->stack_a->num);
	//ps->stack_a->num = ps->stack_a->next->num;
	//printf("stack b: %d", ps->stack_b->num);
	printf("size: %d", i);
}