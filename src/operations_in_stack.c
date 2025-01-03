/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:29:26 by maximart          #+#    #+#             */
/*   Updated: 2024/12/29 20:59:07 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_move(t_stack *stack_a, t_stack *stack_b, int target)
{
	int	count;
	int	index;

	index = find_index(stack_b, target);
	printf("%sCOUNT MOVE INDEX %d%s\n", RED, index, RESET);
	count = 1;
	if (index > 1 && index > (stack_lstsize(stack_b) / 2))
		count += stack_lstsize(stack_b) - index - 1;
	else if (index > 1 && index <= (stack_lstsize(stack_b) / 2))
		count += index - 1;
	index = find_position(stack_a, target);
	printf("%sCOUNT MOVE INDEXXXXXXX %d%s\n", RED, index, RESET);
	if (index > 1 && index > (stack_lstsize(stack_a) / 2))
		count += stack_lstsize(stack_a) - index - 1;
	else if (index > 1 && index <= (stack_lstsize(stack_a) / 2))
		count += index - 1;
	printf("%sCOUNT MOVE COUNT %d%s\n", MAGENTA, count, RESET);
	return (count);
}

int	get_best_move(t_stack *stack_a, t_stack *stack_b)
{
	int		best_move_target;
	int		move_count;
	int		best_move_count;
	t_stack	*temp;

	best_move_target = stack_b->value;
	best_move_count = count_move(stack_a, stack_b, best_move_target);
	printf("%sGET BEST MOVE VALUE_b %d%s\n", RED, stack_b->value, RESET);
	temp = stack_b->next;
	printf("%sGET BEST MOVE TEMP %d%s\n", RED, temp->value, RESET);
	while (temp != stack_b && temp != NULL)
	{
		move_count = count_move(stack_a, stack_b, temp->value);
		printf("%sGET BEST MOVE_count %d%s\n", RED, move_count, RESET);
		if (move_count < best_move_count)
		{
			best_move_count = move_count;
			best_move_target = temp->value;
		}
		temp = temp->next;
	}
	printf("%sBESTMOVE %d%s\n", ORANGE, best_move_target, RESET);
	return (best_move_target);
}

int	elem_in_first_quartils(t_stack *stack, int q1, int q2)
{
	t_stack	*temp;
	int		length;
	int		i;

	length = stack_lstsize(stack);
	i = 0;
	temp = stack;
	while (i < length)
	{
		if (q1 <= temp->value && temp->value <= q2)
			return (1);
		temp = temp->next;
		++i;
	}
	return (0);
}

void	replace_stack(t_stack **stack)
{
	int		min;
	int		index;
	t_stack	*stack_a;

	stack_a = *stack;
	min = find_min(stack_a);
	if (stack_a->value != min)
	{
		index = find_index(stack_a, min);
		if (index <= stack_lstsize(stack_a) / 2)
			while (stack_a->value != min)
				ft_ra(&stack_a);
		else
			while (stack_a->value != min)
				ft_rra(&stack_a);
	}
	(*stack) = stack_a;
}

void	min_to_top(t_stack **stack)
{
	int		min_value;
	int		i;
	t_stack	*current_stack;

	current_stack = *stack;
	min_value = find_min(current_stack);
	if (current_stack->value != min_value)
	{
		i = find_index(current_stack, min_value);
		if (i <= stack_lstsize(current_stack) / 2)
		{
			while (current_stack->value != min_value)
				ft_ra(&current_stack);
		}
		else
		{
			while (current_stack->value != min_value)
				ft_rra(&current_stack);
		}
	}
	(*stack) = current_stack;
}
