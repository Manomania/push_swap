/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:23:49 by maximart          #+#    #+#             */
/*   Updated: 2024/12/12 10:23:39 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *args_to_list(int argc, char **argv)
{
	t_stack *stack = NULL;
	int	i;

	i = 1;
	while (i < argc)
	{
		stack_lstadd_back(&stack, stack_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (stack);
}

static int	check_arguments(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!check_num(argv[i]))
		{
			printf("\033[91mError: Bad argument\033[039m\n");
			return (0);
		}
		if (!check_dup(argc, argv))
		{
			printf("\033[91mError: Duplicates\033[039m\n");
			return (0);
		}
		if (!int_check_min_max(argc, argv))
		{
			printf("\033[91mError: Min or max value reached\033[039m\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;

	if (argc == 1)
	{
		printf("\033[91mError: No arguments\033[039m\n");
		return (1);
	}

	if (!check_arguments(argc, argv))
		return (1);

	stack_a = args_to_list(argc, argv);

	if (stack_is_sorted(stack_a))
	{
		printf("\033[32mSTACK SORTED\033[39m");
		return (free_stack(&stack_a), 0);
	}

	if (stack_lstsize(stack_a) == 3)
		sort_three(&stack_a);
	// else if (stack_lstsize(stack_a) >= 4)
	// {
	// 	//
	// 	// ft_pb(&stack_a, &stack_b);
	// 	// ft_pb(&stack_a, &stack_b);
	// 	// while (!stack_is_sorted(stack_a))
	// 	// {
	// 	//
	// 	// 	handle_push(&stack_a, &stack_b);
	// 	// 	handle_swap(&stack_a, &stack_b);
	// 	// 	handle_rotate(&stack_a, &stack_b);
	// 	// 	handle_rev_rotate(&stack_a, &stack_b);
	// 	// }
	// }
		push_min_to_b(&stack_a, &stack_b);
		push_all_to_a(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}