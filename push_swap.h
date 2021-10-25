/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:20:14 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/24 19:22:19 by elvmarti         ###   ########.fr       */
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
	t_listps	*stack_a_copy;
	int			num_mov;
	int			hold_first;
	int			pos_first;
	int			hold_second;
	int			pos_second;
	int			mid;
}				t_push_swap;

t_listps	*ft_lstnew_ps(int num);
t_listps	*ft_lstlast_ps(t_listps *lst);
void		ft_lstadd_back_ps(t_listps **lst, t_listps *new);
void		ft_lstiter_ps(t_listps *lst, void (*f)(int));
int			ft_lstsize_ps(t_listps *lst);
void		ft_lstdelone_ps(t_listps *lst);
void		ft_lstadd_front_ps(t_listps **lst, t_listps *new);

void		print_stacks(t_push_swap *ps);
void		print_lst(int i);
void		print_str(char *str);

void		rule_sa(t_push_swap *ps);
void		rule_sb(t_push_swap *ps);
void		rule_ss(t_push_swap *ps);
void		rule_pb(t_push_swap **ps);
void		rule_pa(t_push_swap **ps);
void		rule_ra(t_push_swap **ps);
void		rule_rb(t_push_swap **ps);
void		rule_rr(t_push_swap **ps);
void		rule_rra(t_push_swap **ps);
void		rule_rrb(t_push_swap **ps);
void		rule_rrr(t_push_swap **ps);

void		sort_small_stack(t_push_swap *ps, int size);
void		three(t_push_swap *ps);
void		sort_four(t_push_swap *ps, int size);
void		sort_five(t_push_swap *ps, int size);
void		sort_big_stack(t_push_swap *ps, int size);

int			get_min_num(t_push_swap *ps);
int			get_max_num(t_push_swap *ps);
int			get_mid(t_push_swap *ps);
void		sort_copy(t_push_swap *ps);
void		chunks(t_push_swap *ps, int num);

#endif