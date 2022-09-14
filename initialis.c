/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:03:16 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/14 08:50:11 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	*routine(void *arg)
{
	t_philo philo;
	
	philo.mutex_fork = arg;
	pthread_mutex_lock();
	printf("salut a toi %s\n", arg);
	return (routine);
}

void	philo_init(t_prog prog)
{
	int	i;
	int nb_thread;
	t_philo philo;

	i = 0;
	nb_thread = prog.nbr_philo;
	while (i < nb_thread)
	{
		pthread_mutex_init(&philo.mutex_fork, NULL);
	//	philo.index = i;
		philo.dead = 0;
		philo.l_fork = (i - 1) % nb_thread;
		philo.r_fork = i;
		philo.nb_eat = 0;
		printf("Yo les poules\n");
	//	pthread_create(&philo.id, NULL, routine, &philo.mutex_fork);
		pthread_create(&philo.id, NULL, routine, "MON LOULOU");
		i++;
	}
}

t_prog	prog_init(char **argv)
{
	t_prog prog;
	prog.nbr_philo = ft_atoi(argv[1]);
	if (!(prog.philo_id = malloc(sizeof(pthread_t) * prog.nbr_philo)))
		return (prog);
	prog.time_to_die = ft_atoi(argv[2]);
	prog.time_to_eat = ft_atoi(argv[3]);
	prog.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		prog.nbr_must_eat = ft_atoi(argv[5]);
	return (prog);
}
