/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:59:45 by maximart          #+#    #+#             */
/*   Updated: 2024/12/12 20:59:53 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rev_rotate(t_stack **stack)
{
	t_stack *last;
	t_stack *second_last;

	if (!stack || !*stack || !(*stack)->next)
		return (-1);
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (0);
}

int	ft_rra(t_stack **stack_a)
{
	if (!stack_a)
		return (-1);
	ft_rev_rotate(stack_a);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	ft_rrb(t_stack **stack_b)
{
	if (!stack_b)
		return (-1);
	ft_rev_rotate(stack_b);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b)
		return (-1);
	ft_rra(stack_a);
	ft_rra(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
