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

#include "./push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	one;
	int	two;
	int	three;

	one = (*stack_a)->value;
	two = (*stack_a)->next->value;
	three = (*stack_a)->prev->value;
	if ((one < two) && (two > three) && (one < three))
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
	else if ((one < two) && (two > three) && (one > three))
		ft_rra(stack_a);
	else if ((one > two) && (two < three) && (one > three))
		ft_ra(stack_a);
	else if ((one > two) && (two > three))
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else
		ft_sa(stack_a);
}
