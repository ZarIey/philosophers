/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 06:45:21 by ctardy            #+#    #+#             */
/*   Updated: 2023/01/27 17:44:29 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include "../includes/libft/libft.h"

typedef enum e_return
{
	OK,
	ERROR,
}	t_return;

typedef enum e_mutex
{
	PRINT,
	EAT,
	DIE,
	RASSASIED,
	MAX_MU,
}	t_mutex;

typedef struct s_prog
{
	int					nbr_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nbr_must_eat;
	int					dead;
	int					rassasied;
	long				start;
	int					count_fork;
	int					count_philo_rassasied;
	pthread_mutex_t		*mutexes;
}	t_prog;

typedef struct s_philo
{
	int					index;
	int					dead;
	int					l_fork;
	int					r_fork;
	int					nb_eat;
	int					flag;
	long int			last_meal;
	t_prog				*prog_in;
	pthread_mutex_t		*fork;
}	t_philo;

// main

long	time_calculator(void);
void	my_usleep(long int time);

// routine

int		create_and_join(t_prog *prog, t_philo *philo);

// death

int		death_trigger(t_prog *prog, t_philo *philo);

// utils

int		check_if_dead(t_prog *prog);
int		check_meal_count(t_philo *philo);
int		check_if_rassasied(t_philo *philo);
void	im_printing(t_prog *prog, t_philo *philo, char *sentence);
void	im_printing_death(t_prog *prog, t_philo *philo, char *sentence);

// init

int		init_tab_mutex(t_prog *prog);
int		prog_init(char **argv, t_prog *prog);
int		philo_assignment(t_prog *prog, t_philo **philo);

//parsing

int		check_errors(int argc, char **argv);

#endif