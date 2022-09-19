/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:25:04 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/19 14:00:05 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	time_calculator()
{
	struct timeval start;
	
	gettimeofday(&start, NULL);
	return (start.tv_sec + start.tv_usec);
}

// int main()
// {
// 	time_starter();
// }