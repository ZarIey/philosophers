/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:03:16 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/14 14:11:16 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	*routine(void *arg)
{
	// int i = 5;
	t_philo *philo;
	
	philo = (t_philo *)arg;
//	pthread_mutex_init(&philo->mutex_fork, NULL);
//	pthread_mutex_lock(&philo->mutex_fork);
	// pthread_t salut = pthread_self();
	// while (i > 0)
	// {
		// printf("salut a toi %s de pid %ld\n", arg, );
	while (1) 
	{
		printf("salut a toi, l'id de ce philo est %d\n", philo->index);
		usleep(500000 * philo->index);
	}
	// 	i--;
	// }
//	pthread_mutex_unlock(&philo->mutex_fork);
	return (NULL);
}

t_philo *philo_assignement(t_philo *philo_base, int nb_thread, int i)
{
	t_philo	*philo;

	philo = philo_base;
	while (i < nb_thread)
	{
		philo[i].index = i + 1;
		philo[i].dead = 0;
		philo[i].l_fork = (i - 1) % nb_thread;
		philo[i].r_fork = i;
		philo[i].nb_eat = 0;
	//	pthread_mutex_destroy(&philo[i].mutex_fork);
	//	printf("Yo les poules\n");
		i++;
	}
	return(philo_base);
}

void create_and_detach(t_prog prog, t_philo *philo, int nb_thread, int i)
{
	while (i < nb_thread)
	{
		pthread_create(&prog.philo_id[i], NULL, routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < nb_thread)
	{
		pthread_detach(prog.philo_id[i]);
		i++;
	}
	while (1);
}

void	philo_init(t_prog prog)
{
	int nb_thread;
	t_philo *philo;
	
	nb_thread = prog.nbr_philo;
	philo = malloc(sizeof(t_philo) * nb_thread);
	philo = philo_assignement(philo, nb_thread, 0);
	create_and_detach(prog, philo, nb_thread, 0);
}

t_prog	prog_init(char **argv)
{
	t_prog		prog;

	prog.nbr_philo = ft_atoi(argv[1]);
	prog.time_to_die = ft_atoi(argv[2]);
	prog.time_to_eat = ft_atoi(argv[3]);
	prog.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		prog.nbr_must_eat = ft_atoi(argv[5]);
	return (prog);
}