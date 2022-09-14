/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:03:16 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/14 11:21:32 by ctardy           ###   ########.fr       */
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
	while (1) {
		printf("salut a toi, id de ce philo est %d\n", philo->index);
		usleep(500000 * philo->index);
	}
	// 	i--;
	// }
	printf("ye fini\n");
//	pthread_mutex_unlock(&philo->mutex_fork);
	return (NULL);
}

void	philo_init(t_prog prog)
{
	int	i;
	int nb_thread;
	t_philo *philo;
	pthread_t *th;

	i = 0;
	nb_thread = prog.nbr_philo;
	// malloc structure que tu vas envoyer
	philo = malloc(sizeof(t_philo) * nb_thread);

	// malloc tableau de thread
	th = malloc(sizeof(pthread_t) * nb_thread);

	// initialise chaque structure de philo
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

	//create thread
	i = 0;
	while (i < nb_thread)
	{
		pthread_create(&th[i], NULL, &routine, &philo[i]);
		i++;
	}

	// detach thread
	i = 0;
	while (i < nb_thread)
	{
		pthread_detach(th[i]);
		i++;
	}
	while (1);
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
