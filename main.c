/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:03:55 by ctardy            #+#    #+#             */
/*   Updated: 2023/01/31 12:40:36 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

long	time_calculator(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000));
}

void	my_usleep(long int time)
{
	long	now;

	now = time_calculator();
	while (time_calculator() <= now + time)
		usleep(50);
}

void	destroy_mutex(t_prog *prog, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->prog_in->nbr_philo)
	{
		pthread_mutex_destroy(&philo->fork[i++]);
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
	if (check_errors(argc, argv))
		return (1);
	prog_init(argv, &prog);
	nb_thread = prog.nbr_philo;
	philo_assignment(&prog, &philo, nb_thread, i);
	create_and_join(&prog, philo, nb_thread, i);
	destroy_mutex(&prog, philo);
	free(philo->fork);
	free(philo);
	return (0);
}
