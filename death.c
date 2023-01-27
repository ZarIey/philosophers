/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:10:41 by ctardy            #+#    #+#             */
/*   Updated: 2023/01/27 17:51:33 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

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
		pthread_mutex_lock(&prog->mutexes[RASSASIED]);
		if (philo->prog_in->count_fork > 1 && philo->prog_in->count_philo_rassasied >= philo->prog_in->nbr_philo)
		{
			printf("ON A TOUS MANGER %d REPAS\n", philo->prog_in->nbr_must_eat);
			pthread_mutex_unlock(&prog->mutexes[RASSASIED]);
			break ;
		}
		pthread_mutex_unlock(&prog->mutexes[RASSASIED]);
		if (!check_if_rassasied(philo) && last_meal && time_calculator() - last_meal > prog->time_to_die)
		{
			pthread_mutex_lock (&prog->mutexes[DIE]);
			prog->dead = 1;
			im_printing_death(prog, &philo[i], "died");
			pthread_mutex_unlock (&prog->mutexes[DIE]);
			break ;
		}
		i = (i + 1) % prog->nbr_philo;
		usleep (200);
	}
	return (OK);
}
