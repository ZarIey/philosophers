/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:03:16 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/12 09:48:03 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

t_prog	prog_init(char **argv)
{
	t_prog prog;
	prog.number_of_philosophers = ft_atoi(argv[1]);
	prog.time_to_die = ft_atoi(argv[2]);
	prog.time_to_eat = ft_atoi(argv[3]);
	prog.time_to_sleep = ft_atoi(argv[4]);
	prog.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	return (prog);
}
