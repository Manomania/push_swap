/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:00:56 by maximart          #+#    #+#             */
/*   Updated: 2024/12/12 21:00:59 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || stack_lstsize(*stack) < 2)
		return (-1);
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	return (0);
}

/**
 * @brief	Performs the "sa" operation on a given stack.
 *			The operation swap the firsts 2 elements of the stack.
 * @param	stack_a: A pointer to the t_stack on which the operation is performed.
 *			The stack must be valid and contain at least 2 elements.
 * @return	0 if the operation is successful, -1 otherwise.
 */
int	ft_sa(t_stack **stack_a)
{
	if (ft_swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

/**
 * @brief	Performs the "sb" operation on a given stack
*			The operation swap the firsts 2 elements of the stack.
 * @param	stack_b: A pointer to the t_stack on which the operation is performed.
 *			The stack must be valid and contain at least 2 elements.
 * @return	0 if the operation is successful, -1 otherwise.
 */
int	ft_sb(t_stack **stack_b)
{
	if (ft_swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

/**
 * @brief	Performs the "ss" operation on two stacks
 *  *		The operation swap the firsts 2 elements of the two stack.
 * @param	stack_a: A pointer to the t_stack on which the operation is performed.
 *			The stack must be valid and contain at least 2 elements.
 * @param	stack_b: A pointer to the t_stack on which the operation is performed.
 *			The stack must be valid and contain at least 2 elements.
 * @return	0 if the operation is successful, -1 otherwise.
 */
int	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_lstsize(*stack_a) < 2 || stack_lstsize(*stack_b) < 2)
		return (-1);
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}