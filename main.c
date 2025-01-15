/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:23:49 by maximart          #+#    #+#             */
/*   Updated: 2025/01/15 20:04:58 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// t_stack	*fill_stack(int *argc, char **split_args)
// {
// 	t_stack	*stack;
// 	int		i;
//
// 	stack = malloc(sizeof(t_stack));
// 	if (!stack)
// 		return (NULL);
// 	i = 0;
// 	while (i < *argc)
// 	{
// 		if (check_error(stack, argc, split_args))
// 			return (NULL);
// 		add_to_list(&stack, ft_atoi(split_args[i]));
// 		free(split_args[i]);
// 		i++;
// 	}
// 	return (stack);
// }
//
// static t_stack	*split_one_argument(int *argc, char **argv)
// {
// 	t_stack	*stack;
// 	int		i;
// 	char	**split_args;
//
// 	stack = NULL;
// 	split_args = ft_split(argv[1], ' ');
// 	if (!split_args)
// 		return (NULL);
// 	i = 0;
// 	while (split_args[i])
// 		i++;
// 	stack = fill_stack(argc, split_args);
// 	free_split(split_args);
// 	*argc = i + 1;
// 	return (stack);
// }

static t_stack	*args_to_list(int *argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < *argc)
	{
		add_to_list(&stack, ft_atoi(argv[i]));
		i++;
	}
	return (stack);
}

static void	free_both(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(&stack_a);
	free_stack(&stack_b);
}

static void	launch_algo(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	if (data->size > 3 && !stack_is_sorted(stack_a))
		ft_sort(&stack_a, &stack_b, data);
	free_both(stack_a, stack_b);
	free(data);
	exit(1);
}

static void	multiple_choice(int ac, char **av, t_stack *s_a, t_data *data)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (stack_lstsize(s_a) == 2 && !stack_is_sorted(s_a))
		ft_sa(&s_a);
	else if (stack_lstsize(s_a) == 3)
		sort_three(&s_a);
	else
	{
		data = malloc(sizeof(t_data));
		if (!data)
		{
			free_stack(&s_a);
			return ;
		}
		get_median_quartil(&s_a, stack_lstsize(s_a), &data);
		free_stack(&s_a);
		s_a = args_to_list(&ac, av);
		launch_algo(s_a, stack_b, data);
		free(data);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	*data;

	stack_b = NULL;
	data = NULL;
	if (check_error(argc, argv))
		return (1);
	stack_a = args_to_list(&argc, argv);
	if (!stack_is_sorted(stack_a))
		multiple_choice(argc, argv, stack_a, data);
	free_both(stack_a, stack_b);
	return (0);
}
