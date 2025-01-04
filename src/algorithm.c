/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:50:47 by maximart          #+#    #+#             */
/*   Updated: 2025/01/04 19:12:15 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_for_opti(t_stack **s_a, t_stack **s_b, int pos_a, int pos_b)
{
	int	i;
	int	length_a;
	int	length_b;

	i = 0;
	length_a = stack_lstsize(*s_a);
	length_b = stack_lstsize(*s_b);
	if ((pos_a <= (length_a / 2)) && (pos_b <= (length_b / 2)))
	{
		while (i < pos_a && i < pos_b)
		{
			ft_rr(s_a, s_b);
			i++;
		}
	}
	return (i);
}

static void	rotate_b_to_pos(t_stack **stack_b, int pos_b)
{
	int	len;

	len = stack_lstsize(*stack_b);
	if (pos_b <= len / 2)
		while (pos_b--)
			ft_rb(stack_b);
	else
	{
		pos_b = len - pos_b;
		while (pos_b--)
			ft_rrb(stack_b);
	}
}

static void	rotate_a_to_pos(t_stack **stack_a, int pos_a)
{
	int	len;

	len = stack_lstsize(*stack_a);
	if (pos_a <= len / 2)
		while (pos_a--)
			ft_ra(stack_a);
	else
	{
		pos_a = len - pos_a;
		while (pos_a--)
			ft_rra(stack_a);
	}
}

void	insertion_sort(t_stack **stack_a, t_stack **stack_b, int b_move)
{
	int	pos_a;
	int	pos_b;
	int	optimized;

	pos_a = find_position((*stack_a), b_move);
	pos_b = find_index((*stack_b), b_move);
	optimized = check_for_opti(stack_a, stack_b, pos_a, pos_b);
	pos_a -= optimized;
	pos_b -= optimized;
	rotate_b_to_pos(stack_b, pos_b);
	rotate_a_to_pos(stack_a, pos_a);
	ft_pa(stack_a, stack_b);
}

void	push_a_optimize(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	data->size -= 3;
	while (data->size)
	{
		insertion_sort(&stack_a, &stack_b, get_best_move(stack_a, stack_b));
		data->size--;
	}
	replace_stack(&stack_a);
	stack_b = NULL;
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(data);
	exit(1);
}
