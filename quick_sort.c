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

#include "./push_swap.h"

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
			if (i == NULL)
				i = low;
			else
				i = i->next;
			swap_nodes(i, j);
		}
		j = j->next;
	}
	return (i);
}

static void	quick_sort_recursive(t_stack *low, t_stack *high)
{
	t_stack	*pivot;

	if (!low || !high || low == high || low == high->next)
		return ;
	pivot = partition(low, high);
	if (pivot && pivot != low)
		quick_sort_recursive(low, pivot->prev);
	if (pivot && pivot != high)
		quick_sort_recursive(pivot->next, high);
}

static t_stack	*get_last_node(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current && current->next != stack)
		current = current->next;
	return (current);
}

void	quick_sort_stack(t_stack **stack)
{
	t_stack	*last;

	if (!(*stack))
		return ;
	last = get_last_node(*stack);
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
