/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:27:23 by ctardy            #+#    #+#             */
/*   Updated: 2023/01/31 12:46:13 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	mutex_security(t_prog *prog, t_philo *philo, int flag)
{
	if (!flag)
	{	
		pthread_mutex_lock(&philo->fork[philo->l_fork]);
		pthread_mutex_lock(&philo->prog_in->mutexes[FORK]);
		prog->count_fork++;
		pthread_mutex_unlock(&philo->prog_in->mutexes[FORK]);
		im_printing(prog, philo, "has taken a fork 🍴");
		if (philo->prog_in->nbr_philo < 2)
		{
			pthread_mutex_unlock(&philo->fork[philo->l_fork]);
			return ;
		}
		pthread_mutex_lock(&philo->fork[philo->r_fork]);
		pthread_mutex_lock(&philo->prog_in->mutexes[FORK]);
		prog->count_fork++;
		pthread_mutex_unlock(&philo->prog_in->mutexes[FORK]);
		im_printing(prog, philo, "has taken a fork 🍴");
		return ;
	}
	pthread_mutex_unlock(&philo->fork[philo->l_fork]);
	pthread_mutex_unlock(&philo->fork[philo->r_fork]);
}

int	eating(t_prog *prog, t_philo *philo)
{
	mutex_security(prog, philo, 0);
	pthread_mutex_lock(&philo->prog_in->mutexes[FORK]);
	if (prog->count_fork < 2)
	{
		pthread_mutex_unlock(&philo->prog_in->mutexes[FORK]);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->prog_in->mutexes[FORK]);
	pthread_mutex_lock(&philo->prog_in->mutexes[EAT]);
	im_printing(prog, philo, "is eating 🍽");
	philo->last_meal = time_calculator();
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->prog_in->mutexes[EAT]);
	my_usleep(prog->time_to_eat);
	mutex_security(prog, philo, 1);
	return (OK);
}

void	*routine(void *philo_arg)
{
	t_philo	*philo;

	philo = philo_arg;
	if (philo->index % 2)
		my_usleep(philo->prog_in->time_to_eat);
	while ("Drill")
	{
		if (check_if_dead(philo->prog_in))
			break ;
		if (eating(philo->prog_in, philo))
			break ;
		im_printing(philo->prog_in, philo, "is sleeping 🛌");
		my_usleep(philo->prog_in->time_to_sleep);
		if (check_meal_count(philo))
		{
			pthread_mutex_lock(&philo->prog_in->mutexes[RASSASIED]);
			philo->prog_in->count_philo_rassasied++;
			pthread_mutex_unlock(&philo->prog_in->mutexes[RASSASIED]);
			break ;
		}
		if (check_if_rassasied(philo))
			break ;
		im_printing(philo->prog_in, philo, "is thinking 🧐");
	}
	return (NULL);
}

int	create_and_join(t_prog *prog, t_philo *philo, int nb_thread, int i)
{
	pthread_t	*all_philo;

	all_philo = malloc (sizeof(pthread_t) * nb_thread);
	if (all_philo == NULL)
		return (ERROR);
	while (i < nb_thread)
	{
		if (pthread_create(&all_philo[i], NULL, routine, &philo[i]))
		{
			while (i > 0)
			{
				pthread_join(all_philo[i], NULL);
				i--;
				free(all_philo);
				return (ERROR);
			}
		}
		i++;
	}
	death_trigger(prog, philo);
	i = 0;
	while (i < nb_thread)
		pthread_join(all_philo[i++], NULL);
	free(all_philo);
	return (OK);
}
