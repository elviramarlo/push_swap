/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:20:14 by elvmarti          #+#    #+#             */
/*   Updated: 2021/09/29 19:57:27 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_listps
{
	int				num;
	struct s_listps	*next;
}				t_listps;

typedef struct s_push_swap
{
	t_listps	*stack_a;
	t_listps	*stack_b;
	int			num_mov;
}				t_push_swap;

t_listps	*ft_lstnew_ps(int num);
t_listps	*ft_lstlast_ps(t_listps *lst);
void		ft_lstadd_back_ps(t_listps **lst, t_listps *new);
void		ft_lstiter_ps(t_listps *lst, void (*f)(int));
int			ft_lstsize_ps(t_listps *lst);
void		ft_lstdelone_ps(t_listps *lst, void (*del)(int));

void		print_stacks(t_push_swap *ps);
void		print_lst(int i);
void		print_error(char *str);

void		rule_sa(t_push_swap *ps);
void		rule_sb(t_push_swap *ps);
void		rule_ss(t_push_swap *ps);
void		rule_pa(t_push_swap *ps);

#endif