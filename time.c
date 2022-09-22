/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:25:04 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/22 06:17:30 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

long	time_calculator()
{
	struct timeval start;
	
	gettimeofday(&start, NULL);
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000));
}

int	time_diff(t_prog prog, t_philo philo, int time2)
{
	int	result;

	result = time2 - philo.last_meal;
	   printf("VALEUR DE LAST IHT %d\n", philo.last_meal);
	  printf("VALEUR DE TIME NOW %d\n", time2);
	  printf("VALEUR DE RESULT %d\n", result);
	if (result > prog.time_to_die)
		return (1);
	return (0);
}
// int main()
// {
// 	time_starter();
// }