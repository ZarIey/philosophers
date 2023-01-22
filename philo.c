/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:27:23 by ctardy            #+#    #+#             */
/*   Updated: 2023/01/22 19:00:17 by ctardy           ###   ########.fr       */
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
	while (i < MAX_MU)
	{
	// 	pthread_mutex_destroy(&prog->fork[i]);
	// 	i++;
		printf("JE DELETE LA\n");
		pthread_mutex_destroy(&prog->mutexes[i++]);
	}
}

// // int	time_diff(t_prog prog, t_philo philo, int time2)
// // {
// // 	int	result;
// // 	//(void)prog;
// // //	printf("OUAIS JE RENTRE LA OOH\n");
// // //	printf("VALEUR DE LAST MEAL %d\n", philo.last_meal);
// // //	printf("VALEUR DE NOW %d\n", time2);
// // 	result = time2 - philo.last_meal;
// // 	if (result > prog.time_to_die)
// // 	 	return (1);
// // 	return (result);
// // }

// void	im_printing(t_prog *prog, t_philo philo, char *sentence)
// {
// 		pthread_mutex_lock(&prog->print);
// 		printf("%ld %d %s\n", (time_calculator() - prog->start), philo.index, sentence);
// 		if (prog->dead)
// 		{
// 			pthread_mutex_lock(&prog->dead_lock);
// 			my_usleep(150);
// 		//	pthread_mutex_unlock(&philo.prog_in->stop);
// 		//	return ;
// 		}
// 		pthread_mutex_unlock(&prog->print);
// 		pthread_mutex_unlock(&prog->dead_lock);
// }

// void death_trigger(t_prog *prog, t_philo *philo)
// {
// 	int i;

// 	i = 0;
// 	//printf("Valeur de time actuel %ld pour philo %d\n", time_calculator() - philo->last_meal, philo->index);
// 	//printf("Valeur de time__to_die %d pour philo %d\n", prog->time_to_die, philo->index);
// 	//printf("Valeur de last meal %ld pour philo %d\n", time_calculator() - philo->last_meal, philo->index);
// 	if (!prog->end_eat)
// 	{
// 		if (!prog->dead && i < prog->nbr_philo)
// 		{
// 			pthread_mutex_lock(&(prog->is_alive));
// 			if (prog->time_to_die <= time_calculator() - (philo->last_meal))
// 			{
// 				// printf("%ld %d %s\n", (time_calculator() - prog->start), philo[i].index, "died");
// 				prog->dead = 1;
// 				pthread_mutex_lock(&prog->print);
// 				im_printing(prog, philo[i], "died");
// 				pthread_mutex_unlock(&(prog->is_alive));
// 				pthread_mutex_unlock(&philo->prog_in->stop);
// 			//	printf("CA IMPRIME PLU\n");
// 				//pthread_mutex_unlock(&prog->print);
// 				return;
// 			}
// 			pthread_mutex_unlock(&(prog->is_alive));
// 			i++;
// 		}
// 		if (prog->dead)
// 			return ;
// 		// i = 0;
// 	//	printf("%d\n", i);
// 	}
// 	//printf("coucou a tosu et a totu\n");
// }

// void mutex_security(t_prog *prog, t_philo philo, int flag)
// {
// 	if (!flag)
// 	{	
// 	//	printf("Valeur de la lfork : %d\n", philo.l_fork);
// 		pthread_mutex_lock(&prog->fork[philo.l_fork]);
// 	//	printf("VVVVVVVVVVVVVVVVVVVV");
// 		//exit(0);
// 		im_printing(prog, philo, "has taken a fork");
// 		// printf("%d %d has taking a fork\n", time_calculator(), philo.index);
// 		pthread_mutex_lock(&prog->fork[philo.r_fork]);
// 		im_printing(prog, philo, "has taken a fork");
// 		// printf("%d %d has taking a fork\n", time_calculator(), philo.index);	
// 		return ;
// 	}
// 	pthread_mutex_unlock(&prog->fork[philo.l_fork]);
// 	pthread_mutex_unlock(&prog->fork[philo.r_fork]);
// }

// void	eating(t_prog *prog, t_philo *philo)
// {
// 	if (philo->flag)
// 	{
// 		if ((prog->time_to_eat * 2) >= prog->time_to_die)
// 		{
// 				my_usleep(prog->time_to_die);
// 				im_printing(prog, *philo, "died");
// 				pthread_mutex_lock(&prog->print);
// 				pthread_mutex_unlock(&philo->prog_in->stop);
// 		}
// 	}
// 	mutex_security(prog, *philo, 0);
// 	im_printing(prog, *philo, "is eating");
// 	philo->last_meal = time_calculator();
// 	my_usleep(prog->time_to_eat);
// //	printf(" VALEUR PHILO %d SUR LAST MEAL %ld\n",philo->index, time_calculator() - prog->start);	
// 	//printf(" VALEUR APRES LE VELO SUR LE CUL DU PHLO %d SUR LA PROM MANGER %ld\n",philo->index, time_calculator() - prog->start);	
// 	mutex_security(prog, *philo, 1);
// }

// void	*routine(void *arg)
// {
// 	t_philo *philo;
// 	int		count_philo;
	
// 	count_philo = 0;
// 	philo = (t_philo *)arg;
	
// //	pthread_mutex_lock(&philo->prog_in->routine);
// 	if (philo->index % 2 == 0)
// 	{
// 		my_usleep(philo->prog_in->time_to_eat);
// 		philo->flag = 1;
// 	}
// 	while (!(philo->prog_in->dead))
// 	{
// 		//printf("ARRETE TOI\n");
// 		//death_trigger(philo->prog_in, philo);
// 		eating(philo->prog_in, philo);
// 		philo->nb_eat++;
// 		//printf("LE NBR DE EAT LAAAA %d\n", philo->nb_eat);
// 		//printf("PHILO %d A MANGER %d TIMES\n", philo->index, philo->nb_eat);
// 		if (philo->nb_eat == philo->prog_in->nbr_must_eat)
// 		{
// 			pthread_mutex_lock(&philo->prog_in->rassasied);
// 			philo->prog_in->end_eat = 1;
// 			philo->prog_in->count_philo_rassasied++;
// 			pthread_mutex_unlock(&philo->prog_in->rassasied);
// 			//printf("VALEUR DE COUNT RASSASIED %d\n", philo->prog_in->count_philo_rassasied);
// 			//printf ("ON EST TOUJOURS %d\n", philo->prog_in->nbr_philo);
// 			if (philo->prog_in->count_philo_rassasied == philo->prog_in->nbr_philo)
// 			{
// 				pthread_mutex_lock(&philo->prog_in->print);
// 				my_usleep(200);
// 				printf("OLALA ON A TOUS BIEN MANGE %d REPAS CHACUN LA \n", philo->prog_in->nbr_must_eat);
// 				pthread_mutex_unlock(&philo->prog_in->stop);
// 				return (NULL);
// 			}
						
// 		}
// 		im_printing(philo->prog_in, *philo, "is sleeping");
// 		// printf("%d %d is sleeping\n", time_calculator(), philo->index);
// 		my_usleep(philo->prog_in->time_to_sleep);
// 		im_printing(philo->prog_in, *philo, "is thinking");
// 		// printf("%d %d is thinking\n", time_calculator(), philo->index);
// 	//	pthread_mutex_unlock(&philo->prog_in->routine);
// 	}
// 		//printf("------------ Nombre de repas : %d de %d\n", philo->nb_eat, philo->index);
// 	return (NULL);
// }

// void create_and_detach(t_prog *prog, t_philo *philo, int nb_thread, int i)
// {
// 	while (i < nb_thread)
// 	{
// 		//philo[i].last_meal = time_calculator();
// 		//printf("Valeur de last meal : %d\n", philo[i].last_meal);
		
// 		pthread_create(&prog->philo_id[i], NULL, routine, &philo[i]);
// 		//death_trigger(prog, philo);
// 		//printf("Ok ca m'as l'air good\n");	
// 		i++;
// 	}
	
// 	//death_trigger(prog, prog->tab_philo);
// 	i = 0;
// 	while (i < nb_thread)
// 	{
// 		// printf("YOO\n");
// 		pthread_detach(prog->philo_id[i]);
// 		//printf("Destruction du thread %d\n", i);
// 		i++;
// 	}
// 	return;
// }

int	philo_assignement(t_prog *prog, t_philo *philo_base, int nb_thread, int i)
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
		philo[i].flag = 0;
		philo[i].prog_in = prog;
		philo[i].last_meal = time_calculator();
		i++;
	}
	return (OK);
}


// pthread_mutex_t	*mutex_init(t_prog *prog)
// {
// 	pthread_mutex_t *tab;
// 	int	i;

// 	tab = prog->fork;
// 	i = 0;
// 	if (!(tab = malloc(sizeof(pthread_mutex_t) * prog->nbr_philo)))
// 		return (NULL);
// 	while (i < prog->nbr_philo)
// 	{
// 		pthread_mutex_init(&tab[i], NULL);
// 	//	printf("nbr de mutex : %d\n", i);
// 		i++;
// 	}
// 	pthread_mutex_init(&prog->print, NULL);
// 	pthread_mutex_init(&prog->rassasied, NULL);
// 	pthread_mutex_init(&prog->dead_lock, NULL);
// 	return (tab);
// }

int	philo_init(t_prog *prog, t_philo **philo)
{
	*philo = malloc(sizeof(t_philo) * prog->nbr_philo);
	if (philo == NULL)
		return (ERROR);
//	printf("Creation du tab de philos ok\n");
	return (OK);
	//create_and_join(prog, prog->tab_philo, prog->nbr_philo, 0);
}

int	init_tab_mutex(t_prog *prog)
{
	pthread_mutex_t *mutex;
	
	mutex = malloc(sizeof(pthread_mutex_t) * MAX_MU);
	if (mutex == NULL)
		return (ERROR);
	int i = 0;
	while (i < MAX_MU)
		pthread_mutex_init(&mutex[i++], NULL);
	prog->mutexes = mutex;
	return (OK);
}

int	prog_init(char **argv, t_prog *prog)
{

	prog->nbr_philo = ft_atoi(argv[1]);
	prog->time_to_die = ft_atoi(argv[2]);
	prog->time_to_eat = ft_atoi(argv[3]);
	prog->time_to_sleep = ft_atoi(argv[4]);
	prog->start = time_calculator();
	prog->count_philo_rassasied = 0;
	if (argv[5])
		prog->nbr_must_eat = ft_atoi(argv[5]);
	else 
		prog->nbr_must_eat = -1;
	if (init_tab_mutex(prog))
		return (ERROR);
	return (OK) ;
}

int main (int argc, char **argv)
{
	t_prog	prog;
	t_philo	*philo;

	philo = NULL;
	if (check_errors(argc, argv))
		return (1);
	prog_init(argv, &prog);
	philo_init(&prog, &philo);
	printf("Checkpoint\n");
	printf("nbr philos %d meurs en %d\n", prog.nbr_philo, prog.time_to_die);
//	exit(0);
//	philo_assignment();
// 	int i = 0;
// 	while (1)
// 	{ .  
// 		i = 0;
// 		while (i < prog.nbr_philo)
// 			death_trigger(&prog, &prog.tab_philo[i++]);
// 	}
// 	pthread_mutex_lock(&prog.stop);
// 	pthread_mutex_lock(&prog.stop);
	destroy_mutex(&prog);
	free(philo);
	system("leaks philo");
	//exit(0);
	return (0);
}