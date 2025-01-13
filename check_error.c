/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:10:26 by maximart          #+#    #+#             */
/*   Updated: 2025/01/04 20:10:30 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	check_arguments(int argc, char **argv)
{
	int	i;

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

int	check_error(int argc, char **argv)
{
	if (!check_arguments(argc, argv))
		return (1);
	return (0);
}
