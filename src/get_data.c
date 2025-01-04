/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:43:33 by maximart          #+#    #+#             */
/*   Updated: 2025/01/03 10:43:35 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_nth_node(t_stack *stack, int n)
{
	t_stack	*current;
	int		count;

	current = stack;
	count = 1;
	while (current != NULL && count < n)
	{
		current = current->next;
		count++;
	}
	return (current);
}

void	get_median_quartil(t_stack **stack, int size, t_data **data)
{
	t_stack	*temp;

	temp = NULL;
	if (!(*stack))
		return ;
	temp = *stack;
	quick_sort_stack(&temp);
	(*data)->size = size;
	(*data)->med = (size + 1) / 2;
	fill_data(data, stack_lstsize(temp), temp);
	(*data)->med = get_nth_node(temp, (*data)->med)->value;
}
