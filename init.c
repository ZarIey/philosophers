/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:14:56 by ctardy            #+#    #+#             */
/*   Updated: 2023/02/04 14:43:16 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	philo_assignment(t_prog *prog, t_philo **philo, int nb_thread, int i)
{
	pthread_mutex_t	*fork;

	*philo = malloc(sizeof(t_philo) * prog->nbr_philo);
	if (philo == NULL)
		return (ERROR);
	fork = malloc(sizeof(pthread_mutex_t) * prog->nbr_philo);
	while (i < prog->nbr_philo)
		pthread_mutex_init(&fork[i++], NULL);
	i = 0;
	while (i < nb_thread)
	{
		(*philo)[i].index = i + 1;
		(*philo)[i].dead = 0;
		(*philo)[i].l_fork = (i - 1) % nb_thread;
		if ((*philo)[i].l_fork < 0)
			(*philo)[i].l_fork = nb_thread - 1;
		(*philo)[i].r_fork = i;
		(*philo)[i].nb_eat = 0;
		(*philo)[i].flag = 0;
		(*philo)[i].prog_in = prog;
		(*philo)[i].fork = fork;
		(*philo)[i].last_meal = prog->start;
		i++;
	}
	return (OK);
}

int	init_tab_mutex(t_prog *prog)
{
	int				i;
	pthread_mutex_t	*mutex;

	mutex = malloc(sizeof(pthread_mutex_t) * MAX_MU);
	if (mutex == NULL)
		return (ERROR);
	i = 0;
	while (i < MAX_MU)
		pthread_mutex_init(&mutex[i++], NULL);
	prog->mutexes = mutex;
	return (OK);
}

int	prog_init(char **argv, t_prog *prog)
{
	prog->nbr_philo = mini_atoi(argv[1]);
	prog->time_to_die = mini_atoi(argv[2]);
	prog->time_to_eat = mini_atoi(argv[3]);
	prog->time_to_sleep = mini_atoi(argv[4]);
	prog->start = time_calculator();
	prog->count_philo_rassasied = 0;
	prog->rassasied = 0;
	prog->count_fork = 0;
	prog->dead = 0;
	if (argv[5])
		prog->nbr_must_eat = mini_atoi(argv[5]);
	else
		prog->nbr_must_eat = -1;
	if (init_tab_mutex(prog))
		return (ERROR);
	return (OK);
}
