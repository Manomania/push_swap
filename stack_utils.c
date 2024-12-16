/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:33:53 by maximart          #+#    #+#             */
/*   Updated: 2024/12/16 09:33:55 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void update_indices(t_stack *stack)
{
	int index = 0;
	while (stack)
	{
		stack->index = index++;
		stack = stack->next;
	}
}

int find_max_index(t_stack *stack)
{
	int max_value;
	int max_index;

	if (!stack)
		return (-1);

	max_value = stack->value;
	max_index = stack->index;

	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_index = stack->index;
		}
		stack = stack->next;
	}
	return (max_index);
}


int find_min_index(t_stack *stack)
{
	int min_value;
	int min_index;

	if (!stack)
		return (-1);

	min_value = stack->value;
	min_index = stack->index;

	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_index = stack->index;
		}
		stack = stack->next;
	}
	return (min_index);
}

int	find_closest(t_stack **stack, int target_index)
{
	int	size_stack;
	int	next;
	int prev;

	if (!stack || !*stack)
		return (0);
	size_stack = stack_lstsize(*stack);
	next = target_index;
	prev = size_stack - target_index;
	if (next <= prev)
		return (next);
	else
		return (-prev);
}