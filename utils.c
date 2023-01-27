/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:18:33 by ctardy            #+#    #+#             */
/*   Updated: 2023/01/27 17:55:05 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	im_printing(t_prog *prog, t_philo *philo, char *sentence)
{
	pthread_mutex_lock(&prog->mutexes[PRINT]);
	if (!check_if_dead(prog))
		printf("%ld %d %s\n", (time_calculator() - prog->start), philo->index, sentence);
	pthread_mutex_unlock(&prog->mutexes[PRINT]);
}

void	im_printing_death(t_prog *prog, t_philo *philo, char *sentence)
{
	pthread_mutex_lock(&prog->mutexes[PRINT]);
	printf("%ld %d %s\n", (time_calculator() - prog->start), philo->index, sentence);
	pthread_mutex_unlock(&prog->mutexes[PRINT]);
}

int	check_meal_count(t_philo *philo)
{
	if (philo->nb_eat == philo->prog_in->nbr_must_eat)
		return (ERROR);
	return (OK);
}

int	check_if_dead(t_prog *prog)
{
	pthread_mutex_lock(&prog->mutexes[DIE]);
	if (prog->dead)
	{
		pthread_mutex_unlock(&prog->mutexes[DIE]);
		return (ERROR);
	}
	pthread_mutex_unlock(&prog->mutexes[DIE]);
	return (OK);
}

int	check_if_rassasied(t_philo *philo)
{	
	pthread_mutex_lock(&philo->prog_in->mutexes[EAT]);
	if (philo->nb_eat == philo->prog_in->nbr_must_eat)
	{
		pthread_mutex_unlock(&philo->prog_in->mutexes[EAT]);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->prog_in->mutexes[EAT]);
	return (OK);
}
