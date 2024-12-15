/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:01:26 by maximart          #+#    #+#             */
/*   Updated: 2024/12/11 18:01:28 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*normalize(char *str)
{
	if (str[0] == '+')
		return (str + 1);
	return (str);
}

/**
 * @brief Check for duplicate arguments with the function norm
 * @param argc is the number of arguments
 * @param argv is the argument to compare
 * @return int 0 if duplicates are found, 1 otherwise
 */
int	check_dup(int argc, char **argv)
{
	int		i;
	int		j;
	char	*norm_i;
	char	*norm_j;

	i = 1;
	while (i < argc)
	{
		norm_i = normalize(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			norm_j = normalize(argv[j]);
			if (ft_strncmp(norm_i, norm_j, argc) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Checks if the string contains only digits, + or -, and no spaces.
 * @param str The string to validate.
 * @return int 1 if the string do not contain only digits, 0 otherwise.
 */
int	check_num(const char *str)
{
	int	i;

	i = 0;
	if (!*str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i] || str[i] == ' ')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		if (ft_isdigit(str[i]) && str[i + 1] == ' ')
			return (0);
		i++;
	}
	return (1);
}