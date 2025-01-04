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

#include "../include/push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	ft_ra(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next != *stack_a)
	{
		ft_rotate(stack_a);
		ft_putendl_fd("ra", 1);
	}
}

void	ft_rb(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next != *stack_b)
	{
		ft_rotate(stack_b);
		ft_putendl_fd("rb", 1);
	}
}

void	ft_rr(t_stack **s_a, t_stack **s_b)
{
	if (*s_a && (*s_a)->next != *s_a && *s_b && (*s_b)->next != *s_b)
	{
		ft_rotate(s_a);
		ft_rotate(s_b);
		ft_putendl_fd("rr", 1);
	}
}
