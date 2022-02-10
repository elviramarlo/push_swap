/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 00:24:24 by elvmarti          #+#    #+#             */
/*   Updated: 2022/02/10 17:04:55 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(char *str)
{
	print_str(str);
	exit(-1);
}

void	print_str(char *str)
{
	int	i;

	i = ft_strlen(str);
	write (1, str, i);
	write (1, "\n", 1);
}
