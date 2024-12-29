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

#include "../push_swap.h"

int find_min(t_stack *stack)
{
	int min_value;

	min_value = stack->value;
	while (stack)
	{
		if (stack->value < min_value)
			min_value = stack->value;
		stack = stack->next;
	}
	return (min_value);
}

int	find_max(t_stack *stack)
{
	int max_value;

	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
			max_value = stack->value;
		stack = stack->next;
	}
	return (max_value);
}

int	find_index(t_stack *stack, int value)
{
	int i;

	i = 0;
	while (stack->value != value)
	{
		i++;
		stack = stack->next;
	}
	stack->index = 0;
	return (i);
}

int	find_position(t_stack *stack, int target)
{
	t_stack	*temp;
	int	min;
	int i;

	min = find_min(stack);
	if (target > find_max(stack) || target < min)
		return (find_index(stack, min));
	temp = stack;
	i = 0;
	while (i < stack_lstsize(stack))
	{
		if (temp->next && temp->value < target && target < temp->next->value)
			return (i);
		temp = temp->next;
		i++;
	}
	return (0);
}