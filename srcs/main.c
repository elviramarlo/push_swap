/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:40:23 by elvmarti          #+#    #+#             */
/*   Updated: 2021/10/26 16:41:25 by elvmarti         ###   ########.fr       */
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
		{
			print_str("Error");
			exit(1);
		}
		while (argv[x][y] == ' ')
			y++;
		if (argv[x][y] == '\0')
		{
			print_str("Error");
			exit(1);
		}
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
			&& !ft_strchr(argv[i], '-'))
		{
			print_str("Error");
			exit(1);
		}
		if (ft_isalpha(argv[i][y]))
		{
			print_str("Error");
			exit(1);
		}
		if (argv[i][y] == '-' && (argv[i][y + 1] == ' ' ||
			argv[i][y + 1] == '-' || argv[i][y + 1] == '\0'))
		{	
			print_str("Error");
			exit(1);
		}
		y++;
	}
	check_only_spaces(argv);
}

static void	sort_nums(t_push_swap *ps)
{
	int	size;

	size = ft_lstsize_ps(ps->stack_a);
	if (size <= 5)
		sort_small_stack(ps, size);
	else if (size > 5)
		sort_big_stack(ps, size);
	print_stacks(ps);
	printf("NUM MOVS: %d\n", ps->num_mov);
	exit(0);
}

int	main(int argc, char **argv)
{
	int			i;
	int			y;
	char		**tmp;
	int			num;
	t_push_swap	ps;

	ft_bzero(&ps, sizeof(t_push_swap));
	i = 1;
	if (argc < 2)
	{
		print_str("Error");
		exit(1);
	}
	else
	{
		while (argv[i])
		{
			check_arg(argv, i);
			tmp = ft_split(argv[i], ' ');
			i++;
			y = 0;
			while (tmp[y])
			{
				num = ft_atoi(tmp[y]);
				ft_lstadd_back_ps(&ps.stack_a, ft_lstnew_ps(num));
				ft_lstadd_back_ps(&ps.stack_a_copy, ft_lstnew_ps(num));
				sort_copy(&ps);
				y++;
			}
		}
	}
	sort_nums(&ps);
}
