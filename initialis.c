/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:03:16 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/15 08:40:59 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	*routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;
	// int i = 0;
	while (philo->nb_eat < philo->prog.nbr_must_eat)
	{
		printf("%d %d is eating\n", time_calculator(), philo->index);
		philo->nb_eat++;
		usleep(philo->prog.time_to_eat);
		printf("%d %d is thinking\n", time_calculator(), philo->index);
		usleep(250000);
		printf("%d %d is sleeping\n", time_calculator(), philo->index);
		usleep(philo->prog.time_to_sleep);
	}
	return (NULL);
}

// void	mutex_init(t_philo *philo, int nb_thread, int i)
// {
// 	while (i < nb_thread)
// 	{
// 		mutex_init
// 	}
// }

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
	while (philo->nb_eat < philo->prog.nbr_must_eat)
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

// void useless_fonction_ptdr_jsuis_une_galere_moi()
// {
// 	ceci est une fonction inutile;
// 	sert a rien;
// 	jpep;
// 	return (qqchose);
// }

void	philo_init(t_prog prog)
{
	int nb_thread;
	t_philo *philo;
	
	nb_thread = prog.nbr_philo;
	philo = malloc(sizeof(t_philo) * nb_thread);
	philo = philo_assignement(prog, philo, nb_thread, 0);
	if (prog.eat_specified)
		create_and_detach(prog, philo, nb_thread, 0);
	else 
		test_test(prog, philo, nb_thread, 0);
	// mutex_init(philo, nb_tread, 0);
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
	{
		prog.nbr_must_eat = ft_atoi(argv[5]);
		prog.eat_specified = 1;
	}
	else 
	{
		prog.nbr_must_eat = 999999999;
		prog.eat_specified = 0;	
	}
	return (prog);
}