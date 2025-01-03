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

// void	sort_three(t_stack **stack_a)
// {
// 	if (find_min(*stack_a) == (*stack_a)->value)
// 	{
// 		ft_rra(stack_a);
// 		ft_sa(stack_a);
// 	}
// 	else if (find_max(*stack_a) == (*stack_a)->value)
// 	{
// 		ft_ra(stack_a);
// 		if (!stack_is_sorted(*stack_a))
// 			ft_sa(stack_a);
// 	}
// 	else
// 	{
// 		if (find_index(*stack_a, find_max(*stack_a)) == 1)
// 			ft_rra(stack_a);
// 		else
// 			ft_sa(stack_a);
// 	}
// }

void	sort_three(t_stack **pile_a)
{
	int	fst;
	int	scd;
	int	trd;

	fst = (*pile_a)->value;
	scd = (*pile_a)->next->value;
	trd = (*pile_a)->prev->value;
	if ((fst < scd) && (scd > trd) && (fst < trd))
	{
		ft_rra(pile_a);
		ft_sa(pile_a);
	}
	else if ((fst < scd) && (scd > trd) && (fst > trd))
		ft_rra(pile_a);
	else if ((fst > scd) && (scd < trd) && (fst > trd))
		ft_ra(pile_a);
	else if ((fst > scd) && (scd > trd))
	{
		ft_sa(pile_a);
		ft_rra(pile_a);
	}
	else
		ft_sa(pile_a);
}