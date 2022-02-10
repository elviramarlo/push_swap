/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lists2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:15:30 by elvmarti          #+#    #+#             */
/*   Updated: 2022/02/10 17:05:03 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstdelone_ps(t_listps *lst)
{
	if (lst)
		free(lst);
}

void	ft_lstadd_front_ps(t_listps **lst, t_listps *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize_ps(t_listps *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
