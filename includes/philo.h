/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 06:45:21 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/12 12:08:34 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILO_H_
#define _PHILO_H_

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

typedef struct s_mutex
{
	pthread_mutex_t mutex;
}	t_mutex;

typedef struct s_prog
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
}	t_prog;


int		check_errors(int argc, char **argv);
t_prog	prog_init(char **argv);

#endif