/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:27:23 by ctardy            #+#    #+#             */
/*   Updated: 2023/01/26 19:56:04 by ctardy           ###   ########.fr       */
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
		usleep(50);
}

void	im_printing(t_prog *prog, t_philo *philo, char *sentence)
{
		pthread_mutex_lock(&prog->mutexes[PRINT]);
		printf("%ld %d %s\n", (time_calculator() - prog->start), philo->index, sentence);
		pthread_mutex_unlock(&prog->mutexes[PRINT]);
}

void mutex_security(t_prog *prog, t_philo *philo, int flag)
{
	if (!flag)
	{	
		pthread_mutex_lock(&philo->fork[philo->l_fork]);
		im_printing(prog, philo, "has taken a fork");
		printf("philo %d fork gauche n. %d\n",philo->index, philo->l_fork);
		pthread_mutex_lock(&philo->fork[philo->r_fork]);
		im_printing(prog, philo, "has taken a fork");
		printf("philo %d fork droite n. %d\n",philo->index, philo->r_fork);
		return ;
	}
	pthread_mutex_unlock(&philo->fork[philo->l_fork]);
	pthread_mutex_unlock(&philo->fork[philo->r_fork]);
}

int	check_meal_count(t_philo *philo)
{
	if (philo->nb_eat == philo->prog_in->nbr_must_eat)
		return (ERROR);
	return (OK);
}

void	eating(t_prog *prog, t_philo *philo)
{
	mutex_security(prog, philo, 0);
	//printf ("Philo %d fourchette gauche : %d et droite : %d\n", philo->index, philo->l_fork, philo->r_fork);
	pthread_mutex_lock(&philo->prog_in->mutexes[EAT]);
	im_printing(prog, philo, "is eating");
	philo->last_meal = time_calculator();
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->prog_in->mutexes[EAT]);
//	printf("Philo %d eat %d times\n", philo->index, philo->nb_eat);
	my_usleep(prog->time_to_eat);
	mutex_security(prog, philo, 1);
}

int death_trigger(t_prog *prog, t_philo *philo)
{
	int i;
	long int last_meal;

	i = 0;
	while ("Drill")
	{
		pthread_mutex_lock(&prog->mutexes[EAT]);
		last_meal = philo[i].last_meal;
		pthread_mutex_unlock(&prog->mutexes[EAT]);
		if (philo->prog_in->count_philo_rassasied >= philo->prog_in->nbr_philo)
		{
			printf("OLALA ON A TOUS MANGER %d REPAS LA HMMM\n", philo->prog_in->nbr_must_eat);
			break ;
		}
		if (last_meal && time_calculator() - last_meal > prog->time_to_die)
		{
			pthread_mutex_lock (&prog->mutexes[DIE]);
			prog->dead = 1;
			im_printing(prog, &philo[i], "died");
			pthread_mutex_unlock (&prog->mutexes[DIE]);
			break ;
		}
		i = (i + 1) % prog->nbr_philo;
		usleep (200);
	}
	return (OK);
}

int check_if_dead(t_prog *prog)
{
	pthread_mutex_lock(&prog->mutexes[DIE]);
	if (prog->dead)
	{
	//	printf("check de la mort en positif\n");
		pthread_mutex_unlock(&prog->mutexes[DIE]);
		return (ERROR);
	}
	pthread_mutex_unlock(&prog->mutexes[DIE]);
	return (OK);
}

void	*routine(void *philo_arg)
{
	t_philo *philo;
	
	philo = philo_arg;
	if (philo->index % 2)
		my_usleep(philo->prog_in->time_to_eat);
	while ("Drill")
	{
		if (check_if_dead(philo->prog_in))
		{
			printf("HOLA IL EST MORT LA %d\n", philo->index);
			break ;
		}
		eating(philo->prog_in, philo);
		im_printing(philo->prog_in, philo, "is sleeping");
		my_usleep(philo->prog_in->time_to_sleep);
		if (check_meal_count(philo))
		{
			philo->prog_in->count_philo_rassasied++;
			break ;
		}
		im_printing(philo->prog_in, philo, "is thinking");
	}
	return (NULL);
}


int create_and_join(t_prog *prog, t_philo *philo)
{
	int i;
	int	nb_thread;
	pthread_t *all_philo;

	i = 0;
	nb_thread = prog->nbr_philo;
	printf("Valeur de nb_thread %d\n", nb_thread);
	all_philo = malloc (sizeof(pthread_t) * nb_thread);
	if (all_philo == NULL)
		return (ERROR);
	while (i < nb_thread)
	{
		if (pthread_create(&all_philo[i], NULL, routine, &philo[i]))
		{
			while (i > 0)
			{
				pthread_join(all_philo[i], NULL);
				i--;
				free(all_philo);
				return (ERROR);
			}
		}
		i++;
	}
	death_trigger(prog, philo);
	i = 0;
	while (i < nb_thread)
	{
		pthread_join(all_philo[i], NULL);
		i++;	
	}
	free(all_philo);
	return (OK);
}

void	destroy_mutex(t_prog *prog, t_philo *philo)
{
	int i;
	
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

int	philo_assignment(t_prog *prog, t_philo **philo)
{
	int	i;
	int	nb_thread;
	pthread_mutex_t	*fork;
	
	i = 0;
	*philo = malloc(sizeof(t_philo) * prog->nbr_philo);
	if (philo == NULL)
		return (ERROR);
	nb_thread = prog->nbr_philo;
	fork = malloc(sizeof(pthread_mutex_t) * prog->nbr_philo);
	while (i < prog->nbr_philo)
		pthread_mutex_init(&fork[i++], NULL);
	i = 0;
	while (i < nb_thread)
	{
		(*philo)[i].index = i + 1;
		(*philo)[i].dead = 0;
		(*philo)[i].l_fork = (i - 1) % nb_thread;
		if ((*philo)[i].l_fork < 0)
			(*philo)[i].l_fork = nb_thread - 1;
		(*philo)[i].r_fork = i;
		(*philo)[i].nb_eat = 0;
		(*philo)[i].flag = 0;
		(*philo)[i].prog_in = prog;
		(*philo)[i].fork = fork;
		(*philo)[i].last_meal = prog->start;
		i++;
	}
	return (OK);
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
	prog->rassasied = 0;
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
	philo_assignment(&prog, &philo);
	create_and_join(&prog, philo);
	destroy_mutex(&prog, philo);
	free(philo->fork);
	free(philo);
	//system("leaks philo");
	return (0);
}