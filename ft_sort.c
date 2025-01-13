/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:18:40 by maximart          #+#    #+#             */
/*   Updated: 2025/01/04 19:18:45 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_sort(t_stack **s_a, t_stack **s_b, t_data *data)
{
	while (elem_in_first_quartils(*s_a, data->q1, data->q2) && data->size >= 8)
	{
		if ((*s_a)->value >= data->q1 && (*s_a)->value <= data->med)
		{
			ft_pb(s_a, s_b);
			ft_rb(s_b);
		}
		else if ((*s_a)->value <= data->q2 && (*s_a)->value >= data->med)
			ft_pb(s_a, s_b);
		else
			ft_ra(s_a);
	}
	while (stack_lstsize(*s_a) > 3)
	{
		ft_pb(s_a, s_b);
		if ((*s_b)->value < data->med)
			ft_rb(s_b);
	}
	if (!stack_is_sorted(*s_a))
		sort_three(s_a);
	push_a_optimize(*s_a, *s_b, data);
}
