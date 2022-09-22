/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 07:20:56 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/22 05:35:48 by ctardy           ###   ########.fr       */
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
			return (1);
		i++;
	}
	return (0);
}

int check_errors_set(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (1);
	if ((ft_atoi(argv[1]) <= 1) || (ft_atoi(argv[2]) < 1) || (ft_atoi(argv[3]) < 1) || (ft_atoi(argv[4]) < 1))
		return (1);
	while (argv[i])
	{
		if (is_num(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int check_errors(int argc, char **argv)
{
	if (check_errors_set(argc, argv))
	{
		printf ("on a un soucis ! 🚔 \n");
		return (1);
	}
	return (0);
}
