/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 07:20:56 by ctardy            #+#    #+#             */
/*   Updated: 2023/02/04 14:00:49 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	mini_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (sign * result);
		else
			result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (ERROR);
		i++;
	}
	return (OK);
}

int	check_errors_set(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (ERROR);
	if (argc > 5 && mini_atoi(argv[5]) == 0)
		return (2);
	if ((mini_atoi(argv[1]) < 1) || (mini_atoi(argv[2]) <= 1) || \
	(mini_atoi(argv[3]) < 1) || (mini_atoi(argv[4]) < 1))
		return (1);
	while (argv[i])
	{
		if (is_num(argv[i]))
			return (ERROR);
		i++;
	}
	return (OK);
}

int	check_errors(int argc, char **argv)
{
	if (check_errors_set(argc, argv) == 2)
		return (2);
	if (check_errors_set(argc, argv))
		return (ERROR);
	return (OK);
}
