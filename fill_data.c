/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:02:22 by maximart          #+#    #+#             */
/*   Updated: 2024/12/29 23:02:24 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	size_five(t_stack *stack, t_data **data)
{
	t_stack	*current;
	int		i;

	current = stack;
	i = 0;
	while (i < (*data)->q1 && current)
	{
		current = current->next;
		i++;
	}
	if (current)
		(*data)->q1 = current->value;
	else
		(*data)->q1 = 0;
	current = stack;
	i = 0;
	while (i < (*data)->q2 && current)
	{
		current = current->next;
		i++;
	}
	if (current)
		(*data)->q2 = current->value;
	else
		(*data)->q2 = 0;
}

void	fill_data(t_data **data, int size, t_stack *stack)
{
	if (size % 2 == 0)
		(*data)->med = size / 2;
	else
		(*data)->med = (size + 1) / 2;
	(*data)->q1 = ((*data)->med + 1) / 2;
	if ((*data)->med % 2 == 0)
		(*data)->q1 = (*data)->med / 2;
	(*data)->q2 = (*data)->med + (*data)->q1;
	if (size > 5)
	{
		size_five(stack, data);
	}
	else
	{
		(*data)->q1 = 0;
		(*data)->q2 = 0;
	}
}
