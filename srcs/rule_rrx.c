/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rrx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:19:07 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/11 16:56:46 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rule_rra(t_push_swap **ps)
{

	t_listps	*current;
	t_listps	*kthNode;
	int		count;
	int size = ft_lstsize_ps((*ps)->stack_a) - 1;

	count = 1;
	if (size != 0)
	{
		current = (*ps)->stack_a;
		while (count < size && current != NULL)
		{
			current = current->next;
			count++;
		}
		// if (current == NULL)
		//	return ;
		kthNode = current;
		while (current->next != NULL)
			current = current->next;
		current->next = (*ps)->stack_a;
		(*ps)->stack_a = kthNode->next;
		kthNode->next = NULL;
	}

/* 	int i = 1;
	int size;
	t_listps *lst;
	
	(*ps)->num_mov++;
	if ((*ps)->stack_a)
	{
		lst = ft_lstlast_ps((*ps)->stack_a);
		ft_lstadd_front_ps(&(*ps)->stack_a, ft_lstnew_ps(lst->num));
		lst = (*ps)->stack_a;
		size  = ft_lstsize_ps(lst) - 1;
		while(lst != NULL && i < size)
		{
			lst = lst->next;
			i++;
		}
		lst->next = NULL;
		ft_lstdelone_ps(lst);
	} */
}

void	rule_rrb(t_push_swap **ps)
{
	t_listps	*current;
	t_listps	*kthNode;
	int		count;
	int size = ft_lstsize_ps((*ps)->stack_b) - 1;

	count = 1;
	if (size != 0)
	{
		current = (*ps)->stack_b;
		while (count < size && current != NULL)
		{
			current = current->next;
			count++;
		}
		// if (current == NULL)
			//return ;
		kthNode = current;
		while (current->next != NULL)
			current = current->next;
		current->next = (*ps)->stack_b;
		(*ps)->stack_b = kthNode->next;
		kthNode->next = NULL;
	}
	/* t_listps *lst;
	int i = 1;
	int	size;

	(*ps)->num_mov++;
	if ((*ps)->stack_b)
	{
		lst = ft_lstlast_ps((*ps)->stack_b);
		ft_lstadd_front_ps(&(*ps)->stack_b, ft_lstnew_ps(lst->num));
		size = ft_lstsize_ps((*ps)->stack_b) - 1;
		lst = (*ps)->stack_b;
		while(lst != NULL && i < size)
		{
			lst = lst->next;
			i++;
		}
		lst->next = NULL;
		ft_lstdelone_ps(lst);
	} */
}

void	rule_rrr(t_push_swap **ps)
{
	rule_rra(ps);
	rule_rrb(ps);
}