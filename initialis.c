/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:03:16 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/19 14:30:06 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void mutex_security(t_prog prog, t_philo philo, int flag)
{
	if (!flag)
	{	
		pthread_mutex_lock(&prog.fork[philo.l_fork]);
		printf("%d %d has taking a fork\n", time_calculator(), philo.index);
		pthread_mutex_lock(&prog.fork[philo.r_fork]);
		printf("%d %d has taking a fork\n", time_calculator(), philo.index);	
		return ;
	}
	pthread_mutex_unlock(&prog.fork[philo.l_fork]);
	pthread_mutex_unlock(&prog.fork[philo.r_fork]);
}

void	eating(t_prog prog, t_philo philo)
{
	mutex_security(prog, philo, 0);
	printf("%d %d is eating\n", time_calculator(), philo.index);
	usleep(philo.prog_in.time_to_eat);
	mutex_security(prog, philo, 1);
}

void	*routine(void *arg)
{
	t_philo *philo;
	t_prog	prog;
	
	philo = (t_philo *)arg;
	prog = philo->prog_in;
	while (!(prog.dead))
	{
		eating(prog, *philo);
		philo->last_meal = time_calculator();
		philo->nb_eat++;
		if (philo->nb_eat == prog.nbr_must_eat)
			break ;
		printf("%d %d is sleeping\n", time_calculator(), philo->index);
		usleep(philo->prog_in.time_to_sleep);
		printf("%d %d is thinking\n", time_calculator(), philo->index);
	}
	return (NULL);
}

t_philo *philo_assignement(t_prog prog, t_philo *philo_base, int nb_thread, int i)
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
		philo[i].prog_in = prog;
		i++;
	}
	return (philo);
}

void create_and_detach(t_prog prog, t_philo *philo, int nb_thread, int i)
{
	while (philo->nb_eat < philo->prog_in.nbr_must_eat)
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
	}
	printf("aye ye fini\n");
	return;
}

void	philo_init(t_prog prog)
{
	int nb_thread;
	t_philo *philo;
	
	nb_thread = prog.nbr_philo;
	philo = malloc(sizeof(t_philo) * nb_thread);
	philo = philo_assignement(prog, philo, nb_thread, 0);
	create_and_detach(prog, philo, nb_thread, 0);
}

t_prog	prog_init(char **argv)
{
	t_prog		prog;

	prog.nbr_philo = ft_atoi(argv[1]);
	prog.time_to_die = ft_atoi(argv[2]);
	prog.time_to_eat = ft_atoi(argv[3]);
	prog.time_to_sleep = ft_atoi(argv[4]);
	prog.eat_specified = 0;
	if (argv[5])
		prog.nbr_must_eat = ft_atoi(argv[5]);
	else 
		prog.nbr_must_eat = 999999999;
	return (prog);
}