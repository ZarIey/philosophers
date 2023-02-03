/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 07:20:56 by ctardy            #+#    #+#             */
/*   Updated: 2023/02/03 12:51:02 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

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
	if (argc > 5 && ft_atoi(argv[5]) == 0)
		return (2);
	if ((ft_atoi(argv[1]) < 1) || (ft_atoi(argv[2]) <= 1) || \
	(ft_atoi(argv[3]) < 1) || (ft_atoi(argv[4]) < 1))
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
