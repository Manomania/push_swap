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

#include "../push_swap.h"

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
		if (!check_int_min_max(argc, argv))
		{
			printf("\033[91mError: Min or max value reached\033[039m\n");
			return (0);
		}
		i++;
	}
	return (1);
}

t_stack *args_to_list(int argc, char **argv)
{
	t_stack *stack = NULL;
	int	i;

	i = 1;
	while (i < argc)
	{
		add_to_list(&stack, ft_atoi(argv[i]));
		i++;
	}
	return (stack);
}


static void	launch_algo(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	if (data->size > 3)
		if (!stack_is_sorted(stack_a))
			ft_sort(stack_a, stack_b, data);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(data);
	exit(1);
}

void print_data(t_data *data)
{
	if (data == NULL)
	{
		printf("Les données sont vides.\n");
		return;
	}

	printf("Médiane : %d\n", data->med);
	printf("Premier quartile (Q1) : %d\n", data->q1);
	printf("Troisième quartile (Q2) : %d\n", data->q2);
	printf("Taille : %d\n", data->size);
}

void print_sorted_stack(t_stack *stack)
{
	t_stack *temp;

	if (!stack)
		return;

	temp = stack;
	do
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	} while (temp && temp != stack);
}

int main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	t_data *data = NULL;

	if (argc <= 2)
	{
		printf("\033[91mError: No enough arguments\033[039m\n");
		return (1);
	}
	if (!check_arguments(argc, argv))
		return (1);
	stack_a = args_to_list(argc, argv);
	if (stack_is_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	if (stack_lstsize(stack_a) == 2 && !stack_is_sorted(stack_a))
		ft_sa(&stack_a);
	else if (stack_lstsize(stack_a) == 3)
		sort_three(&stack_a);
	else
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (free_stack(&stack_a), 1);
		get_median_quartil(&stack_a, &data);
		stack_a = args_to_list(argc, argv);
		print_data(data);
		// print_sorted_stack(stack_a);
		launch_algo(stack_a, stack_b, data);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(data);
	return (0);
}