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
	t_stack *last;
	t_stack *second_last;

	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ft_rra(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	ft_rev_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	ft_rev_rotate(stack_b);
	ft_putendl_fd("rra", 1);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !*stack_b || !(*stack_a)->next || !(*stack_b)->next)
		return ;
	ft_rra(stack_a);
	ft_rra(stack_b);
	ft_putendl_fd("rrr", 1);
}
