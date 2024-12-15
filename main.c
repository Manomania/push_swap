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
	// t_stack *stack_b = NULL;

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
		else if (!check_dup(argc, argv))
		{
			printf("\033[91mError: Duplicates\033[039m\n");
			return (free_stack(&stack_a), 1);
		}
		i++;
	}
	printf("\033[92mALL GOOD !!!!\033[039m\n");
	return (0);
}