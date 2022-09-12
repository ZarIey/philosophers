/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 06:26:18 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/12 12:04:07 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Les philosophes sont soit en train de manger, de penser ou de dormir.
	Lorsqu’ils mangent, ils ne peuvent pas penser ou dormir.
	Lorsqu’ils dorment, ils ne peuvent pas manger ou penser.
	Enfin, lorsqu’ils pensent, ils ne peuvent pas manger ou dormir.

• Il y a également des fourchettes sur la table. Il y a autant de fourchettes que
de philosophes.

• Puisque servir et manger des spaghetti à l’aide d’une seule fourchette n’est pas
chose facile, un philosophe prend la fourchette sur sa gauche et celle sur sa droite,
soit une fourchette dans chaque main, afin de manger.

• Quand un philosophe a fini de manger, il repose les fourchettes sur la table et se
met à dormir. Une fois réveillé, il se remet à penser. La simulation prend fin si un
philosophe meurt de faim.

• Chaque philosophe a besoin de manger et ne doit pas mourir de faim.
• Les philosophes ne communiquent pas entre eux.
• Les philosophes ne peuvent pas savoir si l’un d’entre eux est sur le point de mourir.
• Inutile de préciser que les philosophes ne doivent pas mourir !

• Chaque programme doit prendre les arguments suivants :
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/

#include "./includes/philo.h"
#include <stdlib.h>


void	eating(pthread_mutex_t mutex, t_prog prog)
{
	pthread_mutex_lock(&mutex);
	printf("HMM JE MANGE BIEN LA 🥘 🍽\n");
	usleep(prog.time_to_eat);
	pthread_mutex_unlock(&mutex);
}

void	sleeping(pthread_mutex_t mutex, t_prog prog)
{
	pthread_mutex_lock(&mutex);
	printf("OLALA COMMENT JE ME REPOSE DE OUF SRX 🌙 😴\n");
	usleep(prog.time_to_sleep);
	pthread_mutex_unlock(&mutex);
}

void	thinking(pthread_mutex_t mutex, t_prog prog)
{
	pthread_mutex_lock(&mutex);
	printf("JE ME POSE PLEIN DE QUESTIONS TDF❓🤯\n");
	usleep(prog.time_to_sleep);
	pthread_mutex_unlock(&mutex);
}

void routine(pthread_mutex_t mutex, t_prog prog)
{
	eating(mutex, prog);
	sleeping(mutex, prog);
	thinking(mutex, prog);
}

void	simple_loop(t_prog prog)
{
	int NB_THREAD = prog.number_of_philosophers;
	pthread_t threads[NB_THREAD];
	pthread_mutex_t mutex;
	
	if (!(pthread_mutex_init(&mutex, NULL)))
		return ;
	for (int i = 0; i < NB_THREAD; i++)
	{
		pthread_create(&threads[i], NULL, routine, &mutex);
		printf("Création du thread numéro %ld\n", threads[i]);
	}
	for (int i = 0; i < NB_THREAD; i++) {
		pthread_join(threads[i], NULL);
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}

int main (int argc, char **argv)
{
	t_prog prog;
	if (check_errors(argc, argv))
		return (1);
	prog = prog_init(argv);
	simple_loop(prog);
	printf("all good\n");
	return (0);
}