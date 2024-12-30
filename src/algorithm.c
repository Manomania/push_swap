/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:15:15 by maximart          #+#    #+#             */
/*   Updated: 2024/12/29 23:15:18 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int check_for_opti(t_stack **stack_a, t_stack **stack_b, int pos_a, int pos_b)
{
	int i = 0;
	int length_a = stack_lstsize(*stack_a);
	int length_b = stack_lstsize(*stack_b);

	if ((pos_a <= (length_a / 2)) && (pos_b <= (length_b / 2)))
	{
		while (i <= (pos_a - 1) && i <= (pos_b - 1))
		{
			ft_rr(stack_a, stack_b);
			i++;
		}
	}
	else if ((pos_a > (length_a / 2)) && (pos_b > (length_b / 2)))
	{
		while (i < (length_a - pos_a) && i < (length_b - pos_b))
		{
			ft_rrr(stack_a, stack_b);
			i++;
		}
	}
	return (i);
}

static t_stack *rr_rra(t_stack *stack_a, int pos_a, int i)
{
	if (pos_a <= (stack_lstsize(stack_a) / 2))
	{
		while (i <= pos_a - 1)
		{
			ft_ra(&stack_a);
			++i;
		}
	}
	else
	{
		while (i < (stack_lstsize(stack_a) - pos_a))
		{
			ft_rra(&stack_a);
			++i;
		}
	}
	return (stack_a);
}

void insertion_sort(t_stack **p_a, t_stack **p_b, int b_move)
{
	int pos_a = find_position((*p_a), b_move);
	int pos_b = find_index((*p_b), b_move);
	int i = check_for_opti(p_a, p_b, pos_a, pos_b);

	while ((*p_b)->value != b_move)
	{
		if (pos_b <= (stack_lstsize((*p_b)) / 2))
			ft_rb(p_b);
		else
			ft_rrb(p_b);
	}
	(*p_a) = rr_rra((*p_a), pos_a, i);
	ft_pa(p_a, p_b);
}

void push_a_optimize(t_stack *stack_a, t_stack *stack_b, t_data *data)
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

void ft_sort(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	printf("Début du tri\n");
	while (elem_in_first_quartils(stack_a, data->q1, data->q2) && data->size >= 8)
	{
		if (stack_a->value >= data->q1 && stack_a->value <= data->med)
		{
			ft_pb(&stack_a, &stack_b);
			ft_rb(&stack_b);
			continue ;
		}
		if (stack_a->value <= data->q2 && stack_a->value >= data->med)
		{
			ft_pb(&stack_a, &stack_b);
			continue ;
		}
		else
			ft_ra(&stack_a);
	}
	while (stack_lstsize(stack_a) > 3)
	{
		ft_pb(&stack_a, &stack_b);
		if (stack_b->value < data->med)
		{
			ft_rb(&stack_b);
		}
	}
	if (!(stack_is_sorted(stack_a)))
	{
		sort_three(&stack_a);
	}
	push_a_optimize(stack_a, stack_b, data);
	printf("Fin du tri\n");
}

