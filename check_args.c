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

#include "./push_swap.h"

static char	*normalize(char *str)
{
	if (str[0] == '+')
		return (str + 1);
	if (str[0] == '-' && str[1] == '0')
		return (str + 1);
	return (str);
}

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

long	ft_atol(const char *str)
{
	int			i;
	long		sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	check_int_min_max(int argc, char **argv)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
