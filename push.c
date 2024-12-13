/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:05:08 by maximart          #+#    #+#             */
/*   Updated: 2024/12/12 21:05:14 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack *temp;

	temp = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = temp;
	return (0);
}

int	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b)
		return (-1);
	ft_push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b)
		return (-1);
	ft_push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
	return (0);
}