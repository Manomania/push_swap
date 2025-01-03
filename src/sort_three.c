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

#include "../include/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	fst;
	int	scd;
	int	trd;

	fst = (*stack_a)->value;
	scd = (*stack_a)->next->value;
	trd = (*stack_a)->prev->value;
	if ((fst < scd) && (scd > trd) && (fst < trd))
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
	else if ((fst < scd) && (scd > trd) && (fst > trd))
		ft_rra(stack_a);
	else if ((fst > scd) && (scd < trd) && (fst > trd))
		ft_ra(stack_a);
	else if ((fst > scd) && (scd > trd))
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else
		ft_sa(stack_a);
}