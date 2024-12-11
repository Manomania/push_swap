/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:23:49 by maximart          #+#    #+#             */
/*   Updated: 2024/12/11 13:19:39 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || ft_lstsize(*stack) < 2)
		return (-1);
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	return (0);
}

int	ft_sa(t_stack **stack_a)
{
	if (ft_swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	ft_sb(t_stack **stack_b)
{
	if (ft_swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	ft_pa()
{

}

int	ft_pb()
{

}

int	ft_ra()
{

}

int	ft_rb()
{

}

int	ft_rr()
{

}

int	ft_rra()
{

}

int	ft_rrb()
{

}

int	ft_rrr()
{

}

int main(int argc, char **argv)
{
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
	printf("\033[92mALL GOOD !!!!\033[039m\n");
	return (0);
}