/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:00:01 by maximart          #+#    #+#             */
/*   Updated: 2024/12/16 11:00:04 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	int	i;
	int	size;

	size = stack_lstsize(stack);
	if (size > 0)
	{
		i = 1;
		while (i++ < size)
		{
			if (stack->value > stack->next->value)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
	return (0);
}
