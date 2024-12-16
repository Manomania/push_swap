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

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void print_list(t_stack *list)
{
	while (list)
	{
		printf("%d -> ", list->value);
		list = list->next;
	}
	printf("NULL\n");
}

int main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	// t_stack	*temp = NULL;

	int i;

	i = 1;
	if (argc == 1)
	{
		printf("\033[91mError: No arguments\033[039m\n");
		return (1);
	}
	while (i < argc)
	{
		if (!check_num(argv[i]))
		{
			printf("\033[91mError: Bad argument\033[039m\n");
			return (free_stack(&stack_a), 1);
		}
		if (!check_dup(argc, argv))
		{
			printf("\033[91mError: Duplicates\033[039m\n");
			return (free_stack(&stack_a), 1);
		}
		i++;
	}
	stack_a = args_to_list(argc, argv);
	if (stack_is_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	if (argc <= 5)
	{

	}
	if (argc > 5)
	{
		push_min_to_b(&stack_a, &stack_b);
		push_all_to_a(&stack_a, &stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	// printf("Final stack\n");
	// print_list(stack_a);
	// print_list(stack_b);
	return (0);
}