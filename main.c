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

void free_list(t_stack *list)
{
	t_stack *temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
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

int main(int argc, char **argv)
{
	t_stack *stack;
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
			return (1);
		}
		else if (!check_dup(argc, argv))
		{
			printf("\033[91mError: Duplicates\033[039m\n");
			return (1);
		}
		i++;
	}
	stack = args_to_list(argc, argv);
	radix_sort(&stack);
	printf("\033[92mSorted List: \033[039m\n");
	print_list(stack);

	free_list(stack);
	printf("\033[92mALL GOOD !!!!\033[039m\n");
	return (0);
}