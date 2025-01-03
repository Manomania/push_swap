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

#include "../include/push_swap.h"

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*temp;

	temp = stack->next;
	min = stack->value;
	while (temp != stack && temp != NULL)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*temp;

	temp = stack->next;
	max = stack->value;
	while (temp != stack && temp != NULL)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	find_index(t_stack *stack, int value)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stack;
	while (temp->next != stack)
	{
		if (temp->value == value)
			return (i);
		temp = temp->next;
		++i;
	}
	printf("%sFIND INDEX %d%s\n", GREEN, i, RESET);
	return (i);
}

int	find_position(t_stack *stack, int target)
{
	t_stack	*temp;
	int		min;
	int		i;
	int		size;

	min = find_min(stack);
	printf("%sTARGET %d%s\n", GREEN, target, RESET);
	if (target > find_max(stack) || target < min)
		return (find_index(stack, min));
	size = stack_lstsize(stack);
	i = -1;
	temp = stack;
	while (++i < size)
	{
		if (temp->prev->value < target && target < temp->value)
			return (i);
		temp = temp->next;
	}
	return (0);
}
