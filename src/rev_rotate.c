/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:59:45 by maximart          #+#    #+#             */
/*   Updated: 2024/12/17 11:48:55 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rev_rotate(t_stack **stack)
{
	*stack = (*stack)->prev;
}

void	ft_rra(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->prev)
		return ;
	ft_rev_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->prev)
		return ;
	ft_rev_rotate(stack_b);
	ft_putendl_fd("rra", 1);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !*stack_b || !(*stack_a)->prev || !(*stack_b)->prev)
		return ;
	ft_rra(stack_a);
	ft_rra(stack_b);
	ft_putendl_fd("rrr", 1);
}
