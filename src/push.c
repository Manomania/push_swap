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

#include "../include/push_swap.h"

static void	ft_push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*temp;

	temp = *stack_src;
	if ((*stack_src)->next == *stack_src)
		*stack_src = NULL;
	else
	{
		(*stack_src)->prev->next = (*stack_src)->next;
		(*stack_src)->next->prev = (*stack_src)->prev;
		*stack_src = (*stack_src)->next;
	}
	if (!*stack_dest)
	{
		*stack_dest = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = *stack_dest;
		temp->prev = (*stack_dest)->prev;
		(*stack_dest)->prev->next = temp;
		(*stack_dest)->prev = temp;
		*stack_dest = temp;
	}
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_putendl_fd("pb", 1);
}
