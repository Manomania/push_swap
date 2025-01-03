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

#include "../include/push_swap.h"


static void	ft_swap(t_stack **stack)
{
	int	temp;

	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

/**
 * @brief	Performs the "sa" operation on a given stack.
 *			The operation swap the firsts 2 elements of the stack.
 * @param	stack_a: A pointer to the t_stack on which the operation is performed.
 *			The stack must be valid and contain at least 2 elements.
 * @return	0 if the operation is successful, -1 otherwise.
 */
void	ft_sa(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	ft_putendl_fd("sa", 1);
}

/**
 * @brief	Performs the "sb" operation on a given stack
*			The operation swap the firsts 2 elements of the stack.
 * @param	stack_b: A pointer to the t_stack on which the operation is performed.
 *			The stack must be valid and contain at least 2 elements.
 * @return	0 if the operation is successful, -1 otherwise.
 */
void	ft_sb(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	ft_putendl_fd("sb", 1);
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
void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a  || !*stack_b || !(*stack_a)->next || !(*stack_b)->next)
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl_fd("ss", 1);
}