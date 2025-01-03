/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:35:07 by maximart          #+#    #+#             */
/*   Updated: 2024/12/29 22:35:10 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_nodes(t_stack *a, t_stack *b)
{
	int	temp;

	temp = a->value;
	a->value = b->value;
	b->value = temp;
}

static t_stack	*partition(t_stack *low, t_stack *high)
{
	int		pivot;
	t_stack	*i;
	t_stack	*j;

	pivot = high->value;

	i = low->prev;
	j = low;

	while (j != high->next)
	{
		if (j->value <= pivot)
		{
			i = (i == NULL) ? low : i->next;
			swap_nodes(i, j);
		}
		j = j->next;
	}
	return (i);
}

static void	quick_sort_recursive(t_stack *low, t_stack *high)
{
	if (!low || !high || low == high || low == high->next)
		return;

	t_stack *pivot = partition(low, high);

	if (pivot && pivot != low)
		quick_sort_recursive(low, pivot->prev);
	if (pivot && pivot != high)
		quick_sort_recursive(pivot->next, high);
}

t_stack *get_last_node(t_stack *stack)
{
	t_stack *current = stack;
	while (current && current->next != stack)
		current = current->next;
	return (current);
}

void quick_sort_stack(t_stack **stack)
{
	if (!stack || !(*stack))
		return;

	t_stack *last = get_last_node(*stack);

	if (last)
		last->next = NULL;
	if (*stack)
		(*stack)->prev = NULL;

	quick_sort_recursive(*stack, last);

	last = get_last_node(*stack);
	if (last)
		last->next = *stack;
	if (*stack)
		(*stack)->prev = last;
}

static t_stack *get_nth_node(t_stack *stack, int n)
{
	t_stack *current = stack;
	int count = 1;

	while (current != NULL && count < n)
	{
		current = current->next;
		count++;
	}
	return current;
}

void	get_median_quartil(t_stack **stack, int size, t_data **data)
{
	t_stack	*temp = NULL;

	if (!stack || !(*stack))
		return ;
	temp = *stack;
	quick_sort_stack(&temp);
	(*data)->size = size;
	(*data)->med = (size + 1) / 2;
	fill_data(data, stack_lstsize(temp), temp);
	(*data)->med = get_nth_node(temp, (*data)->med)->value;
}

