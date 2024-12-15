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

/**
 * @brief	Performs the "pa" operation on a given stack.
 *			The operation swap the firsts elements of the stack_b
 *			to the top of stack_a.
 * @param	stack_a: A pointer to the t_stack on which the operation is
 *			performed.
 *			The stack must be valid.
 * @param	stack_b: A pointer to the t_stack on which the operation is
 *			performed.
 *			The stack must be valid.
 * @return	0 if the operation is successful, -1 otherwise.
 */
int	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b)
		return (-1);
	ft_push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
	return (0);
}

/**
 * @brief	Performs the "pb" operation on a given stack.
 *			The operation swap the firsts elements of the stack_b to the top
 *			of stack_a.
 * @param	stack_a: A pointer to the t_stack on which the operation is
 *			performed.
 *			The stack must be valid.
 * @param	stack_b: A pointer to the t_stack on which the operation is
 *			performed.
 *			The stack must be valid.
 * @return	0 if the operation is successful, -1 otherwise.
 */
int	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b)
		return (-1);
	ft_push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
	return (0);
}