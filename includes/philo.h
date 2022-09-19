/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 06:45:21 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/19 14:38:20 by ctardy           ###   ########.fr       */
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

typedef struct s_prog
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_must_eat;
	int				eat_specified;
	int				dead;
	pthread_t		*philo_id;
	pthread_mutex_t	*fork;
}	t_prog;

typedef struct s_philo
{
	int				index;
	int				dead;
	int				l_fork;
	int				r_fork;
	int				nb_eat;
	int				last_meal;
	t_prog			prog_in;
}	t_philo ;

// parsing

int		check_errors(int argc, char **argv);
t_prog	prog_init(char **argv);

// time

int	time_calculator();

// init

void	philo_init();

#endif