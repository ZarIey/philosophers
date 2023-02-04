/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:03:55 by ctardy            #+#    #+#             */
/*   Updated: 2023/02/04 16:54:59 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

long	time_calculator(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000));
}

void	my_usleep(t_prog *prog, long int time)
{
	long	now;

	now = time_calculator();
	while (time_calculator() <= now + time)
	{
		if (!check_if_dead(prog))
		{
			usleep(50);
			continue ;
		}
		break ;
	}
}

void	destroy_mutex(t_prog *prog, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->prog_in->nbr_philo)
	{
		pthread_mutex_destroy(&philo->fork[i]);
		i++;
	}
	i = 0;
	while (i < MAX_MU)
		pthread_mutex_destroy(&prog->mutexes[i++]);
}

int	main(int argc, char **argv)
{
	int		i;
	int		nb_thread;
	t_prog	prog;
	t_philo	*philo;

	i = 0;
	philo = NULL;
	if (check_errors(argc, argv) == 2)
		return (!!printf("🚯 Aucun philo n'a mange (la honte) 🍜\n"));
	if (!!check_errors(argc, argv))
		return (!!printf("On a un soucis d'arguments ! 🚔 \n"));
	if (prog_init(argv, &prog))
		return (!!printf("Failed to init prog structure\n"));
	nb_thread = prog.nbr_philo;
	if (philo_assignment(&prog, &philo, nb_thread, i))
		return (!!printf("Failed to assign philo arguments\n"));
	if (create_and_join(&prog, philo, nb_thread, i))
		return (!!printf("Failed to init tab of philos\n"));
	destroy_mutex(&prog, philo);
	free(philo->fork);
	free(philo);
	return (0);
}
