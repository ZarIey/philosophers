/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:10:41 by ctardy            #+#    #+#             */
/*   Updated: 2023/02/04 15:30:13 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	all_done_eating(t_prog *prog, t_philo *philo)
{
	pthread_mutex_lock(&prog->mutexes[RASSASIED]);
	pthread_mutex_lock(&prog->mutexes[FORK]);
	if (philo->prog_in->count_fork > 1 && \
	philo->prog_in->count_philo_rassasied >= philo->prog_in->nbr_philo)
	{
		printf("🥘 Tous les philos ont mange %d repas HMMM 🍜\n", \
		philo->prog_in->nbr_must_eat);
		pthread_mutex_unlock(&prog->mutexes[RASSASIED]);
		pthread_mutex_unlock(&prog->mutexes[FORK]);
		return (ERROR);
	}
	pthread_mutex_unlock(&prog->mutexes[RASSASIED]);
	pthread_mutex_unlock(&prog->mutexes[FORK]);
	return (OK);
}

void	death_by_starve(t_prog *prog, t_philo *philo, int i)
{
	pthread_mutex_lock (&prog->mutexes[DIE]);
	prog->dead = 1;
	im_printing_death(prog, &philo[i], "died 🚑");
	pthread_mutex_unlock (&prog->mutexes[DIE]);
}

int	death_trigger(t_prog *prog, t_philo *philo)
{
	int		i;
	long	last_meal;

	i = 0;
	while ("Drill")
	{
		pthread_mutex_lock(&prog->mutexes[EAT]);
		last_meal = philo[i].last_meal;
		pthread_mutex_unlock(&prog->mutexes[EAT]);
		if (all_done_eating(prog, philo))
			break ;
		if (!check_if_rassasied(philo) && last_meal \
		&& time_calculator() - last_meal > prog->time_to_die)
		{
			death_by_starve(prog, philo, i);
			break ;
		}
		i = (i + 1) % prog->nbr_philo;
	}
	return (OK);
}
