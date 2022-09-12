/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 07:20:56 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/12 08:06:42 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int check_errors(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 6)
		return (1);
	while (argv[i])
	{
		if (is_num(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	arg_init(char **argv, t_philo philo)
{
	philo.number_of_philosophers = ft_atoi(argv[1]);
	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	philo.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}