/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 06:45:21 by ctardy            #+#    #+#             */
/*   Updated: 2023/01/18 17:54:37 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILO_H_
#define _PHILO_H_

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "../includes/libft/libft.h"

#define FREE		0
#define	TAKEN		1
#define	INFINITE	MAX_LONG

struct s_philo;

typedef struct s_prog
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_must_eat;
	int				end_eat;
	int				dead;
	long			start;
	int				count_philo_rassasied;
	struct s_philo	*tab_philo;
	pthread_t		*philo_id;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	is_alive;
	pthread_mutex_t stop;
}	t_prog;

typedef struct s_philo
{
	int				index;
	int				dead;
	int				l_fork;
	int				r_fork;
	int				nb_eat;
	long int		last_meal;
	t_prog			*prog_in;
}	t_philo;

// parsing

int		check_errors(int argc, char **argv);
void	im_printing(t_prog *prog, t_philo philo, long int time, char *sentence);
t_prog	prog_init(char **argv);

// time

long	time_calculator();
int	time_diff(t_prog prog, t_philo philo, int time2);

// init

void	philo_init(t_prog *prog);

// death

void death_trigger(t_prog *prog, t_philo *philo);

#endif