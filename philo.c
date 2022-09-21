/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 06:26:18 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/22 01:02:35 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

pthread_t	*thread_tab(int nb_philo)
{
	pthread_t	*tab_philo;
	// a corriger quand tu sera moins a chier
	//if (!(prog.philo_id = malloc(sizeof(pthread_t) * nb_philo)))
	tab_philo = malloc(sizeof(pthread_t) * nb_philo);
	return (tab_philo);
}

// pthread_mutex_t	*mutex_tab(int nb_philo)
// {
// 	pthread_mutex_t	*tab_mutex;
// 	// a corriger quand tu sera moins a chier
// 	//if (!(prog.philo_id = malloc(sizeof(pthread_t) * nb_philo)))
// 	tab_mutex = malloc(sizeof(pthread_mutex_t) * nb_philo + 1);
// 	return (tab_mutex);
// }

void	init_tab_mutex(t_prog prog)
{
	int i = prog.nbr_philo;

	while (i > 0)
	{
		pthread_mutex_init(&prog.fork[i], NULL);
		i--;
	}
	pthread_mutex_init(&prog.print, NULL);
}

int main (int argc, char **argv)
{
	t_prog prog;
	if (check_errors(argc, argv))
		return (1);
	prog = prog_init(argv);
	prog.philo_id = thread_tab(prog.nbr_philo);
//	prog.fork = mutex_tab(prog.nbr_philo);
	init_tab_mutex(prog);
	philo_init(prog);
//	destroy_mutex();
	printf("all good\n");
	return (0);
}