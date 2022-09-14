/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:25:04 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/14 07:39:58 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	time_calculator()
{
	struct timeval start;
	struct timeval end;
	
	gettimeofday(&start, NULL);
	printf("seconds : %ld\nmicro seconds : %d\n",
    start.tv_sec, start.tv_usec);
  	gettimeofday(&end, NULL);
	printf("Temps mis par le prog : %ld micro seconds\n",((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
}

// int main()
// {
// 	time_starter();
// }