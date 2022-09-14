/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:03:16 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/14 10:29:24 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	*routine(void *arg)
{
//	t_philo *philo;
	
//	philo = (t_philo *)arg;
//	pthread_mutex_init(&philo->mutex_fork, NULL);
//	pthread_mutex_lock(&philo->mutex_fork);
	printf("salut a toi %s\n", arg);
//	pthread_mutex_unlock(&philo->mutex_fork);
	return (routine);
}

void	philo_init(t_prog prog)
{
	int	i;
	int nb_thread;
	t_philo *philo;

	i = 0;
	nb_thread = prog.nbr_philo;
	philo = malloc(sizeof(pthread_t) * nb_thread);
	while (i < nb_thread)
	{
	//	philo.index = i;
		philo[i].dead = 0;
		philo[i].l_fork = (i - 1) % nb_thread;
		philo[i].r_fork = i;
		philo[i].nb_eat = 0;
		pthread_create(&philo[i].id, NULL, routine, &philo[i]);
		i = 0;
	//	pthread_mutex_destroy(&philo[i].mutex_fork);
	//	printf("Yo les poules\n");
		i++;
	}
	while (i < nb_thread)
	{
		pthread_join(philo[i].id, NULL);
		i++;
	}
}

t_prog	prog_init(char **argv)
{
	t_prog prog;
	prog.nbr_philo = ft_atoi(argv[1]);
	// if (!(prog.philo_id = malloc(sizeof(pthread_t) * prog.nbr_philo)))
	// 	return (prog);
	prog.time_to_die = ft_atoi(argv[2]);
	prog.time_to_eat = ft_atoi(argv[3]);
	prog.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		prog.nbr_must_eat = ft_atoi(argv[5]);
	return (prog);
}
