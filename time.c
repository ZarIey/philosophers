/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:25:04 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/22 02:38:36 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	time_calculator()
{
	struct timeval start;
	
	gettimeofday(&start, NULL);
	return (start.tv_sec * 1000 + start.tv_usec / 1000);
}

int	time_diff(t_prog prog, t_philo philo, int time2)
{
	int	result;

	result = philo.last_meal - time2;
	if (result > prog.time_to_die)
		return (1);
	return (0);
}
// int main()
// {
// 	time_starter();
// }