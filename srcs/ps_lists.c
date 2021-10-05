/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:10:22 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/05 22:42:43 by elvmarti         ###   ########.fr       */
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


void	ft_lstiter_ps(t_listps *lst, void (*f)(int))
{
	t_listps	*ptr;

	if (lst)
	{
		while (lst)
		{
			ptr = lst->next;
			f(lst->num);
			lst = ptr;
		}
	}
}

t_listps	*ft_lstlast_ps(t_listps *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ps(t_listps **lst, t_listps *new)
{
	t_listps	*str;

	str = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		str = ft_lstlast_ps(*lst);
		str->next = new;
	}
}

t_listps	*ft_lstnew_ps(int num)
{
	t_listps	*new;

	new = (t_listps *)malloc(sizeof(t_listps));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}