/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 00:24:24 by elvmarti          #+#    #+#             */
/*   Updated: 2021/09/29 19:42:37 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(int i)
{
	printf("\t  %d\n", i);
}

void	print_stacks(t_push_swap *ps)
{
	write(1, "\n\tSTACK A\n", 10);
	ft_lstiter_ps(ps->stack_a, print_lst);
	write(1, "\n\tSTACK B\n", 10);
	ft_lstiter_ps(ps->stack_b, print_lst);
	write(1, "\n", 2);
}

void	print_error(char *str)
{
	int i;

	i = ft_strlen(str);
	write (1, str, i);
	write (1, "\n", 1);
}
