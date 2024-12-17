/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:56:59 by maximart          #+#    #+#             */
/*   Updated: 2024/12/15 15:57:01 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * @param
 * @param
 * @return
 */
void handle_swap(t_stack **stack_a, t_stack **stack_b)
{
	// if (!*stack_a || !*stack_b)
	// 	return;

	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		if ((*stack_a)->value > (*stack_a)->next->value &&
			(*stack_b)->value > (*stack_b)->next->value)
			ft_ss(stack_a, stack_b);
	}

	if (*stack_a && (*stack_a)->next &&
		(*stack_a)->value > (*stack_a)->next->value)
		ft_sa(stack_a);

	if (*stack_b && (*stack_b)->next &&
		(*stack_b)->value > (*stack_b)->next->value)
		ft_sb(stack_b);
}

/**
 * @brief
 * @param
 * @param
 * @return
 */
void handle_push(t_stack **stack_a, t_stack **stack_b)
{
	// if (!*stack_a || !*stack_b )
	// 	return;

	if ((*stack_a)->value > (*stack_b)->value)
		ft_pa(stack_a, stack_b);
	else
		ft_pb(stack_a, stack_b);
}

/**
 * @brief
 * @param
 * @param
 * @return
 */
void	handle_rotate(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_value_a;
	t_stack	*last_value_b;

	if (!*stack_a || !*stack_b)
		return ;
	last_value_a = stack_lstlast(*stack_a);
	last_value_b = stack_lstlast(*stack_b);
	if ((*stack_a)->value > last_value_a->value &&
		(*stack_b)->value > last_value_b->value)
		ft_rr(stack_a, stack_b);
	else
	{
		if ((*stack_a)->value > last_value_a->value)
			ft_ra(stack_a);
		if ((*stack_b)->value > last_value_b->value)
			ft_rb(stack_b);
	}
}

/**
 * @brief
 * @param
 * @param
 * @return
 */
void	handle_rev_rotate(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_value_a;
	t_stack	*last_value_b;

	if (!*stack_a || !*stack_b)
		return ;
	last_value_a = stack_lstlast(*stack_a);
	last_value_b = stack_lstlast(*stack_b);
	if ((*stack_a)->value > last_value_a->value &&
		(*stack_b)->value > last_value_b->value)
		ft_rrr(stack_a, stack_b);
	else
	{
		if ((*stack_a)->value < last_value_a->value)
			ft_rra(stack_a);
		if ((*stack_b)->value > last_value_b->value)
			ft_rrb(stack_b);
	}
}
