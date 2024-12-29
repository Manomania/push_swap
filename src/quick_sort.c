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
	int temp;
	temp = a->value;
	a->value = b->value;
	b->value = temp;
}

static t_stack *partition(t_stack *low, t_stack *high)
{
	int pivot;
	t_stack *i;
	t_stack *j;

	pivot = high->value;
	i = low->prev;
	j = low;
	while (j != high)
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
	if (i == NULL)
		i = low;
	else
		i = i->next;
	swap_nodes(i, high);
	return (i);
}


static void quick_sort_list(t_stack *low, t_stack *high)
{
	t_stack *pivot;

	if (high != NULL && low != high && low != high->next)
	{
		pivot = partition(low, high);
		quick_sort_list(low, pivot->prev);
		quick_sort_list(pivot->next, high);
	}
}

void	get_median_quartil(t_stack *stack, int len, t_data **data)
{
	if (!stack)
	{
		(*data) = NULL;
		return;
	}
	t_stack *last = stack;
	while (last->next != NULL)
		last = last->next;

	quick_sort_list(stack, last);
	(*data)->med = get_nth_value(stack, (len / 2));
}
