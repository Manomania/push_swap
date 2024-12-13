/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:06:08 by maximart          #+#    #+#             */
/*   Updated: 2024/12/12 21:06:13 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	return (0);
}

/**
 * @brief	Performs the "ra" operation on a given stack.
*			The operation rotate the first element of the stack_b
 *			to the last position within the same stack.
 * @param	stack_a: A pointer to the t_stack on which the operation is performed.
 *			The stack must be valid.
 * @return	0 if the operation is successful, -1 otherwise.
 */
int	ft_ra(t_stack **stack_a)
{
	if (!stack_a)
		return (-1);
	ft_rotate(stack_a);
	ft_putendl_fd("ra", 1);
	return (0);
}

/**
 * @brief	Performs the "rb" operation on a given stack.
 *			The operation rotate the first element of the stack_b
 *			to the last position within the same stack.
 * @param	stack_b: A pointer to the t_stack on which the operation is performed.
 *			The stack must be valid.
 * @return	0 if the operation is successful, -1 otherwise.
 */
int	ft_rb(t_stack **stack_b)
{
	if (!stack_b)
		return (-1);
	ft_rotate(stack_b);
	ft_putendl_fd("rb", 1);
	return (0);
}

/**
 * @brief	Performs the "rr" operation on a given stack.
 *			This operation rotates the first element of stack_a and stack_b
 *			to the last position within their respective stacks.
 * @param	stack_a: A pointer to the t_stack on which the operation is performed.
 *			The stack must be valid.
 * @param	stack_b: A pointer to the t_stack on which the operation is performed.
 *			The stack must be valid.
 * @return	0 if the operation is successful, -1 otherwise.
 */
int	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b)
		return (-1);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}