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
	if (!stack || stack_lstsize(*stack) < 2)
		return (-1);
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	return (0);
}

int	ft_sa(t_stack **stack_a)
{
	if (ft_swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	ft_sb(t_stack **stack_b)
{
	if (ft_swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_lstsize(*stack_a) < 2 || stack_lstsize(*stack_b) < 2)
		return (-1);
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}