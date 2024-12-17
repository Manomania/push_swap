/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:58:20 by maximart          #+#    #+#             */
/*   Updated: 2024/12/17 10:58:22 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_utils(t_stack **stack, int first, int second, int third)
{
	if (first > second && second < third && first < third)
		ft_sa(stack);
	else if (first > second && second > third)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if (first > second && second < third)
		ft_ra(stack);
	else if (first < second && second > third && first < third)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if (first < second && second > third)
		ft_rra(stack);
}

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	sort_three_utils(stack_a, first, second, third);
}
