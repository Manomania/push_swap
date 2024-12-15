/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_radix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:14:51 by maximart          #+#    #+#             */
/*   Updated: 2024/12/15 12:15:57 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_max_dig(int value, int index)
{
	return ((value / index) % 10);
}

int	f_max_val(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void	init_buckets(t_stack *bucket[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		bucket[i] = NULL;
		i++;
	}
}

void	init_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
	}
}