/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 06:26:18 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/14 09:16:11 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

// void routine(pthread_mutex_t mutex, t_prog prog)
// {
	
// }

// void	simple_loop(t_prog prog)
// {
// 	int NB_THREAD = prog.number_of_philosophers;
// 	pthread_t threads[NB_THREAD];
// 	pthread_mutex_t mutex;
	
// 	if (!(pthread_mutex_init(&mutex, NULL)))
// 		return ;
// 	for (int i = 0; i < NB_THREAD; i++)
// 	{
// 		pthread_create(&threads[i], NULL, routine, &mutex);
// 		printf("Création du thread numéro %ld\n", threads[i]);
// 	}
// 	for (int i = 0; i < NB_THREAD; i++) {
// 		pthread_join(threads[i], NULL);
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	return (0);
// }

int main (int argc, char **argv)
{
	t_prog prog;
	if (check_errors(argc, argv))
		return (1);
	prog = prog_init(argv);
	philo_init(prog);
	printf("all good\n");
	return (0);
}