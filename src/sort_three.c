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

void	sort_three(t_stack **pile_a)
{
	int	one;
	int	two;
	int	three;

	one = (*pile_a)->value;
	two = (*pile_a)->next->value;
	three = (*pile_a)->prev->value;
	if ((one < two) && (two > three) && (one < three))
	{
		ft_rra(pile_a);
		ft_sa(pile_a);
	}
	else if ((one < two) && (two > three) && (one > three))
		ft_rra(pile_a);
	else if ((one > two) && (two < three) && (one > three))
		ft_ra(pile_a);
	else if ((one > two) && (two > three))
	{
		ft_sa(pile_a);
		ft_rra(pile_a);
	}
	else
		ft_sa(pile_a);
}
