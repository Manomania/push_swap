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

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl_fd("ss", 1);
}
