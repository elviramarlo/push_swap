/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 00:24:24 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/18 15:22:21 by elvmarti         ###   ########.fr       */
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
