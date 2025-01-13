/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:03:37 by maximart          #+#    #+#             */
/*   Updated: 2024/12/12 21:03:37 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/**
 * @brief	Count the size of a linked list representing a stack.
 * @param	lst A pointer to the first node of the stack.
 * @return	i the length of elements in the stack.
 */
int	stack_lstsize(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	if (stack)
	{
		temp = stack;
		i = 1;
		while (temp->next && temp->next != stack)
		{
			temp = temp->next;
			i++;
		}
		return (i);
	}
	return (0);
}

t_stack	*stack_lstnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*stack_lstlast(t_stack *stack)
{
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
	}
	return (stack);
}

t_stack	*add_to_list(t_stack **stack, int value)
{
	t_stack	*elem;

	elem = stack_lstnew(value);
	if (elem == NULL)
		return (NULL);
	if (*stack == NULL)
	{
		*stack = elem;
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
	}
	else
	{
		elem->prev = (*stack)->prev;
		elem->next = *stack;
		(*stack)->prev->next = elem;
		(*stack)->prev = elem;
	}
	return (*stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	if (!stack || !(*stack))
		return ;
	temp = *stack;
	while (temp)
	{
		next = temp->next;
		free(temp);
		if (next == *stack)
			break ;
		temp = next;
	}
	*stack = NULL;
}
