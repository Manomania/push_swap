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

#include "../include/push_swap.h"

static t_stack	*args_to_list(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
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
			ft_sort(&stack_a, &stack_b, data);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(data);
	exit(1);
}

static void	free_all(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(data);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	*data;

	stack_b = NULL;
	check_error(argc, argv);
	data = malloc(sizeof(t_data));
	if (!data)
		return (free_stack(&stack_a), 1);
	stack_a = args_to_list(argc, argv);
	if (stack_is_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	if (stack_lstsize(stack_a) == 2 && !stack_is_sorted(stack_a))
		ft_sa(&stack_a);
	else if (stack_lstsize(stack_a) == 3)
		sort_three(&stack_a);
	else
	{
		get_median_quartil(&stack_a, stack_lstsize(stack_a), &data);
		free_stack(&stack_a);
		stack_a = args_to_list(argc, argv);
		launch_algo(stack_a, stack_b, data);
	}
	free_all(stack_a, stack_b, data);
	return (0);
}
