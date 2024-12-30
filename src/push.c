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

#include "../push_swap.h"

static void	ft_push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack *temp;

	if (add_to_list(stack_dest, (*stack_src)->value) == NULL)
	{
		free_stack(stack_dest);
		free_stack(stack_src);
		exit(1);
	}
	temp = (*stack_src);
	(*stack_src)->prev->next = (*stack_src)->next;
	(*stack_src)->next->prev = (*stack_src)->prev;
	*stack_src = (*stack_src)->next;
	free(temp);
}

/**
 * @brief	Performs the "pa" operation on a given stack.
 *			The operation swap the firsts elements of the stack_b
 *			to the top of stack_a.
 * @param	stack_a: A pointer to the t_stack on which the operation is
 *			performed.
 * @param	stack_b: A pointer to the t_stack on which the operation is
 *			performed.
 *			The stack must be valid.
 * @return	0 if the operation is successful, -1 otherwise.
 */
void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	ft_push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
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
 * @return	0 if the operation is successful, -1 otherwise.
 */
void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return ;
	ft_push(stack_b, stack_a);
	ft_putendl_fd("pb", 1);
}