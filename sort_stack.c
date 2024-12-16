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

#include "push_swap.h"

void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int direction;
	int	min_index;

	while (*stack_a)
	{
		update_indices(*stack_a);
		min_index = find_min_index(*stack_a);
		direction = find_closest(stack_a, min_index);
		if (min_index == 1)
			ft_sa(stack_a);
		else
		{
			while (direction < 0)
			{
				ft_rra(stack_a);
				direction++;
			}
			while (direction > 0)
			{
				ft_ra(stack_a);
				direction--;
			}
		}
		ft_pb(stack_a, stack_b);
	}
}

void	push_all_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

int	stack_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

