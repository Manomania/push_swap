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

#include "push_swap.h"

/**
 * @brief	Count the size of a linked list representng a stack.
 * @param	lst A pointer to the first node of the stack.
 * @return	i the length of elements in the stack.
 */
int	stack_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_stack	*stack_lstnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack	*stack_lstlast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	stack_lstadd_back(t_stack **lst, t_stack *new)
{
	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
			stack_lstlast(*lst)->next = new;
	}
}