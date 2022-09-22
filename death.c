/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 02:07:00 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/22 06:39:15 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void death_trigger(t_prog prog, t_philo *philo)
{
	int i;

	i = 0;
	while (!prog.end_eat)
	{
		while (!prog.dead && i < prog.nbr_philo)
		{
			pthread_mutex_lock(&(prog.is_alive));
			if (time_diff(prog, philo[i], time_calculator()))
			{
				pthread_mutex_lock(&prog.print);
				printf("%ld %d %s\n", (time_calculator() - prog.start), philo[i].index, "died");
				pthread_mutex_unlock(&prog.print);
				prog.dead = 1;
			}
			pthread_mutex_unlock(&(prog.is_alive));
			i++;
		}
		if (prog.dead)
			break ;
		i = 0;
		while (prog.nbr_must_eat != -1 && i < prog.nbr_philo && philo[i].nb_eat == prog.nbr_must_eat)
			i++;
	//	printf("%d\n", i);
		if (i == prog.nbr_philo)
		{
			// write(1, "OH PUTAING\n", 11);
			prog.end_eat = 1;
		}
	}
}
