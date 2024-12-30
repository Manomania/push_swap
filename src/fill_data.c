/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:02:22 by maximart          #+#    #+#             */
/*   Updated: 2024/12/29 23:02:24 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_data(t_data **data, int size, t_stack *stack)
{
    t_stack	*current;
    int		i;

    (*data)->size = size;
    (*data)->med = (size + 1) / 2;
    if (size % 2 == 0)
        (*data)->med = size / 2;
    (*data)->q1 = ((*data)->med + 1) / 2;
    if ((*data)->med % 2 == 0)
        (*data)->q1 = (*data)->med / 2;
    (*data)->q2 = (*data)->med + (*data)->q1;
    if (size > 5)
    {
        current = stack;
        i = 0;
        while (i < (*data)->q1 && current)
        {
            current = current->next;
            i++;
        }
        (*data)->q1 = current ? current->value : 0;
        current = stack;
        i = 0;
        while (i < (*data)->q2 && current)
        {
            current = current->next;
            i++;
        }
        (*data)->q2 = current ? current->value : 0;
    }
    else
    {
        (*data)->q1 = 0;
        (*data)->q2 = 0;
    }
}
