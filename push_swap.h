/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:52:13 by maximart          #+#    #+#             */
/*   Updated: 2024/12/11 10:52:16 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "super_libft/include/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack	*next;
}		t_stack;

int	main(int argc, char **argv);
int	check_dup(int argc, char **argv);
int	check_num(const char *str);

#endif