/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:40:23 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/29 18:35:05 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_only_spaces(char **argv)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (argv[x])
	{
		if (argv[x][0] == '\0')
			error("Error");
		while (argv[x][y] == ' ')
			y++;
		if (argv[x][y] == '\0')
			error("Error");
		x++;
	}
}

static void	check_arg(char **argv, int i)
{
	int	y;

	y = 0;
	while (argv[i][y])
	{
		if (!ft_isdigit(argv[i][y]) && !ft_strchr(argv[i], ' ')
			&& !ft_strchr(argv[i], '-') && !ft_strchr(argv[i], '+'))
			error("Error");
		if (ft_isalpha(argv[i][y]))
			error("Error");
		if ((argv[i][y] == '-' || argv[i][y] == '+') &&
			(argv[i][y + 1] == ' ' || argv[i][y + 1] == '-' ||
			argv[i][y + 1] == '\0' || argv[i][y + 1] == '+'))
			error("Error");
		y++;
	}
	check_only_spaces(argv);
}

/* 	print_stacks(ps);
	printf("NUM MOVS: %d\n", ps->num_mov); */
/* 	system("leaks push_swap"); */

static void	sort_nums(t_push_swap *ps)
{
	int	size;

	size = ft_lstsize_ps(ps->stack_a);
	if (size <= 5)
		sort_small_stack(ps, size);
	else if (size > 5)
		sort_big_stack(ps, size);
}

/* void	leaks(void)
{
	system("leaks push_swap");
} */

static void	make_list(t_push_swap *ps, char **argv)
{
	int			i;
	int			y;
	char		**tmp;
	int			num;

	i = 1;
	while (argv[i])
	{
		check_arg(argv, i);
		tmp = ft_split(argv[i], ' ');
		i++;
		y = 0;
		while (tmp[y])
		{
			num = ft_atoi(tmp[y]);
			free(tmp[y]);
			ft_lstadd_back_ps(&ps->stack_a, ft_lstnew_ps(num));
			ft_lstadd_back_ps(&ps->stack_a_copy, ft_lstnew_ps(num));
			sort_copy(ps);
			y++;
		}
		free(tmp);
	}
	is_sorted(ps);
}

//atexit(leaks);

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	ft_bzero(&ps, sizeof(t_push_swap));
	if (argc < 2)
		error("Error");
	else
		make_list(&ps, argv);
	sort_nums(&ps);
	exit (0);
}
