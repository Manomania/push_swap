/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:02:44 by maximart          #+#    #+#             */
/*   Updated: 2024/12/15 12:15:57 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_to_bucket(t_stack **stack, t_stack *node)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = node;
		node->next = NULL;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
		node->next = NULL;
	}
}

static void	distribute_to_buckets(t_stack *bucket[10], t_stack *cur, int place)
{
	t_stack	*next;

	while (cur)
	{
		next = cur->next;
		add_to_bucket(&bucket[f_max_dig(cur->value, place)], cur);
		cur = next;
	}
}

static t_stack	*reassemble_bucket(t_stack *bucket[10])
{
	t_stack	*new_stack;
	t_stack	**head;
	int		i;

	new_stack = NULL;
	head = &new_stack;
	i = 0;
	while (i < 10)
	{
		if (bucket[i])
		{
			*head = bucket[i];
			while (*head)
				head = &(*head)->next;
		}
		i++;
	}
	return (new_stack);
}

void	radix_sort(t_stack **stack)
{
	t_stack	*bucket[10];
	t_stack	*cur;
	int		max_value;
	int		place;

	max_value = f_max_val(*stack);
	place = 1;
	while (max_value / place > 0)
	{
		init_buckets(bucket);
		cur = *stack;
		distribute_to_buckets(bucket, cur, place);
		*stack = reassemble_bucket(bucket);
		place *= 10;
	}
	init_index(*stack);
}
