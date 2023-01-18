/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:27:23 by ctardy            #+#    #+#             */
/*   Updated: 2023/01/18 16:44:03 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

long	time_calculator()
{
	
	struct timeval start;
	
	gettimeofday(&start, NULL);
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000));
}

void	my_usleep(long int time)
{
	long toto = time_calculator();
	while (time_calculator() <= toto + time)
		usleep(100);
}

void	destroy_mutex(t_prog *prog)
{
	int i;
	
	i = 0;
	while (i < prog->nbr_philo)
	{
		pthread_mutex_destroy(&prog->fork[i]);
		i++;		
	}
	pthread_mutex_destroy(&prog->print);
	pthread_mutex_destroy(&prog->stop);
	pthread_mutex_destroy(&prog->is_alive);
}

int	time_diff(t_prog prog, t_philo philo, int time2)
{
	int	result;
	//(void)prog;
//	printf("OUAIS JE RENTRE LA OOH\n");
//	printf("VALEUR DE LAST MEAL %d\n", philo.last_meal);
//	printf("VALEUR DE NOW %d\n", time2);
	result = time2 - philo.last_meal;
	if (result > prog.time_to_die)
	 	return (1);
	return (result);
}

void	im_printing(t_prog *prog, t_philo philo, long int time, char *sentence)
{
	if (!prog->dead)
	{
		pthread_mutex_lock(&prog->print);
		printf("%ld %d %s\n", (time - prog->start), philo.index, sentence);
		pthread_mutex_unlock(&prog->print);
	}
		
}

void death_trigger(t_prog *prog, t_philo *philo)
{
	int i;

	i = 0;
	//printf("OUIIIIIIIIIIIIIII %d\n", (time_diff(prog, philo[i], time_calculator())));
	if (!prog->end_eat)
	{
		if (!prog->dead && i < prog->nbr_philo)
		{
			pthread_mutex_lock(&(prog->is_alive));
			if (prog->time_to_die + philo->last_meal <= time_calculator())
			{
				// printf("%ld %d %s\n", (time_calculator() - prog->start), philo[i].index, "died");
				im_printing(prog, philo[i], time_calculator(), "died");
				pthread_mutex_lock(&prog->print);
				pthread_mutex_unlock(&philo->prog_in->stop);
				//pthread_mutex_unlock(&prog->print);
				// prog->dead = 1;
			}
			pthread_mutex_unlock(&(prog->is_alive));
			i++;
		}
		if (prog->dead)
			return ;
		i = 0;
		if (prog->nbr_must_eat != -1 && i < prog->nbr_philo && philo[i].nb_eat == prog->nbr_must_eat)
			i++;
	//	printf("%d\n", i);
		if (i == prog->nbr_philo)
		{
			// write(1, "OH PUTAING\n", 11);
			prog->end_eat = 1;
		}
	}
}

void mutex_security(t_prog *prog, t_philo philo, int flag)
{
	if (!flag)
	{	
	//	printf("Valeur de la lfork : %d\n", philo.l_fork);
		pthread_mutex_lock(&prog->fork[philo.l_fork]);
	//	printf("VVVVVVVVVVVVVVVVVVVV");
		//exit(0);
		im_printing(prog, philo, time_calculator(), "has taken a fork");
		// printf("%d %d has taking a fork\n", time_calculator(), philo.index);
		pthread_mutex_lock(&prog->fork[philo.r_fork]);
		im_printing(prog, philo, time_calculator(), "has taken a fork");
		// printf("%d %d has taking a fork\n", time_calculator(), philo.index);	
		return ;
	}
	pthread_mutex_unlock(&prog->fork[philo.l_fork]);
	pthread_mutex_unlock(&prog->fork[philo.r_fork]);
}

void	eating(t_prog *prog, t_philo *philo)
{
	mutex_security(prog, *philo, 0);
	//if (philo-> last_meal)
	im_printing(prog, *philo, time_calculator(), "is eating");
	philo->last_meal = time_calculator();
	//printf(" VALEUR PHILO %d AVANT MANGER %ld\n",philo->index, time_calculator() - prog->start);	
	my_usleep(prog->time_to_eat);
	//printf(" VALEUR APRES LE VELO SUR LE CUL DU PHLO %d SUR LA PROM MANGER %ld\n",philo->index, time_calculator() - prog->start);	
	mutex_security(prog, *philo, 1);
}

void	*routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;
	
	if (philo->index % 2 == 0)
		my_usleep(philo->prog_in->time_to_eat);
	while (!(philo->prog_in->dead))
	{
		death_trigger(philo->prog_in, philo);
		eating(philo->prog_in, philo);
		philo->nb_eat++;
		//printf("Nombre de repas : %d de %d\n", philo->nb_eat, philo->index);
		if (philo->nb_eat == philo->prog_in->nbr_must_eat)
			break ;
		im_printing(philo->prog_in, *philo, time_calculator(), "is sleeping");
		// printf("%d %d is sleeping\n", time_calculator(), philo->index);
		my_usleep(philo->prog_in->time_to_sleep);
		im_printing(philo->prog_in, *philo, time_calculator(), "is thinking");
		// printf("%d %d is thinking\n", time_calculator(), philo->index);
	}
	return (NULL);
}

void create_and_detach(t_prog *prog, t_philo *philo, int nb_thread, int i)
{
	while (i < nb_thread)
	{
		philo[i].last_meal = time_calculator();
		//printf("Valeur de last meal : %d\n", philo[i].last_meal);
		pthread_create(&prog->philo_id[i], NULL, routine, &philo[i]);
		//death_trigger(prog, philo);
		//printf("Ok ca m'as l'air good\n");	
		i++;
	}
	//death_trigger(prog, prog->tab_philo);
	i = 0;
	while (i < nb_thread)
	{
		// printf("YOO\n");
		pthread_detach(prog->philo_id[i]);
		//printf("Destruction du thread %d\n", i);
		i++;
	}
	return;
}

t_philo *philo_assignement(t_prog *prog, t_philo *philo_base, int nb_thread, int i)
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
		philo[i].last_meal = time_calculator();
		// printf("philo est egal a %d\n", philo[i].index);
		// printf("dead est egal a %d\n", philo[i].dead);
		// printf("lfork est egal a %d\n", philo[i].l_fork);
		// printf("r_fork est egal a %d\n", philo[i].r_fork);
		// printf("nb_eat est egal a %d\n", philo[i].nb_eat);
		// printf("\n");
		//printf("prog_in est egal a %d\n", philo[i].prog_in);
		i++;
	}
	return (philo);
}

void	philo_init(t_prog *prog)
{
	int nb_thread;
	t_philo *philo;
	
	nb_thread = prog->nbr_philo;
//	printf("nbr de thread = %d\n", nb_thread);
	philo = malloc(sizeof(t_philo) * nb_thread);
	philo = philo_assignement(prog, philo, nb_thread, 0);
	//return (philo);
	prog->tab_philo = philo;
	create_and_detach(prog, philo, nb_thread, 0);
}

pthread_mutex_t	*mutex_init(t_prog *prog)
{
	pthread_mutex_t *tab;
	int	i;

	tab = prog->fork;
	i = 0;
	if (!(tab = malloc(sizeof(pthread_mutex_t) * prog->nbr_philo)))
		return (NULL);
	while (i < prog->nbr_philo)
	{
		pthread_mutex_init(&tab[i], NULL);
	//	printf("nbr de mutex : %d\n", i);
		i++;
	}
	pthread_mutex_init(&prog->print, NULL);
	return (tab);
}

pthread_t	*thread_tab(int nb_philo)
{
	pthread_t	*tab_philo;
	// a corriger quand tu sera moins a chier
	//if (!(prog->philo_id = malloc(sizeof(pthread_t) * nb_philo)))
	if (!(tab_philo = malloc(sizeof(pthread_t) * nb_philo)))
		return (NULL);
	return (tab_philo);
}

t_prog	prog_init(char **argv)
{
	t_prog		prog;

	prog.nbr_philo = ft_atoi(argv[1]);
	prog.time_to_die = ft_atoi(argv[2]);
	prog.time_to_eat = ft_atoi(argv[3]);
	prog.time_to_sleep = ft_atoi(argv[4]);
	prog.start = time_calculator();
	if (argv[5])
		prog.nbr_must_eat = ft_atoi(argv[5]);
	else 
		prog.nbr_must_eat = -1;
	return (prog);
}

int main (int argc, char **argv)
{
	t_prog prog;
	if (check_errors(argc, argv))
		return (1);
	prog = prog_init(argv);
	prog.fork = mutex_init(&prog);
	prog.philo_id = thread_tab(prog.nbr_philo);
	philo_init(&prog);
	//printf("valeur de prog->dead %d\n", prog->dead);
	pthread_mutex_init(&prog.stop, NULL);
	pthread_mutex_lock(&prog.stop);
	pthread_mutex_lock(&prog.stop);
	//death_trigger(prog, prog->tab_philo);
	//exit(0);
	free(prog.philo_id);
	free(prog.fork);
	destroy_mutex(&prog);
	return (0);
}

// moins d'appel de fonction redondants (time calculator)
// message de fin de repas limité
// ajouter de couleurs pour le style


/* It looks like you have fixed the issues that I mentioned in my previous answer regarding the order of destroying the mutexes, and handling the case where prog->nbr_must_eat is -1.

However, there may be other issues causing the segfault, such as:

Race conditions between the threads can cause the program to access memory in an unexpected way.
Deadlock caused by threads waiting for each other to release a mutex.
Uninitialized variables or memory leak.
Overrunning the bounds of an array.
To debug the issue, you can try:

Adding some print statements to see the value of variables and the flow of the program.
Use a debugger like gdb to trace the program and see where it crashes.
Check if any of the functions return an error value and handle it accordingly.
Make sure that the memory is allocated properly, and that you are not freeing memory that is still in use.
Also, don't hesitate to check the documentation of the pthread library
If you still can't find the problem, try to isolate the problematic part of the code and test it separately.*/
