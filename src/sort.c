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

#include "../push_swap.h"








int	get_nth_value(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (stack && i < n)
	{
		stack = stack->next;
		i++;
	}
	if (stack)
		return (stack->value);
	return (0);
}

void	calcul_quartils(t_data **data, int len, t_stack *stack)
{
	(*data)->med = get_nth_value(stack, len / 2);
	(*data)->q1 = get_nth_value(stack, ((*data)->med + 1) / 2);
	if ((*data)->med % 2 == 0)
		(*data)->q1 = get_nth_value(stack, (*data)->med / 2);
	(*data)->q2 = get_nth_value(stack, (*data)->med + (*data)->q1);
	if (len > 5)
	{
		(*data)->q1 = get_nth_value(stack, (*data)->q1);
		(*data)->q2 = get_nth_value(stack, (*data)->q2);
	}
	else
	{
		(*data)->q1 = 0;
		(*data)->q2 = 0;
	}
}






static int	count_move(t_stack *stack_a, t_stack *stack_b, int target)
{
	int	count;
	int	index;

	index = find_index(stack_b, target);
	count = 1;
	if (index > 1)
	{
		if (index > (stack_lstsize(stack_b) / 2))
			count += stack_lstsize(stack_b) - index - 1;
		else
			count += index - 1;
	}
	index = find_position(stack_a, target);
	if (index > 1)
	{
		if (index > (stack_lstsize(stack_a) / 2))
			count += stack_lstsize(stack_a) - index - 1;
		else
			count += index - 1;
	}
	return (count);
}

int	get_best_move(t_stack *stack_a, t_stack *stack_b)
{
	int		best_move_target;
	int		best_move_count;
	int		current_move_count;
	t_stack	*current;

	best_move_target = stack_b->value;
	best_move_count = count_move(stack_a, stack_b, best_move_target);
	current = stack_b->next;

	while (current != stack_b && current != NULL)
	{
		current_move_count = count_move(stack_a, stack_b, current->value);
		if (current_move_count < best_move_count)
		{
			best_move_count = current_move_count;
			best_move_target = current->value;
		}
		current = current->next;
	}
	return (best_move_target);
}

int	elem_in_first_quartils(t_stack *stack, int q1, int q2)
{
	t_stack	*tmp;
	int		length;
	int		i;

	length = stack_lstsize(stack);
	i = 0;
	tmp = stack;
	while (i < length)
	{
		if (q1 <= tmp->value && tmp->value <= q2)
			return (1);
		tmp = tmp->next;
		++i;
	}
	return (0);
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
	*stack = current_stack;
}