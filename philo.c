/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 06:26:18 by ctardy            #+#    #+#             */
/*   Updated: 2022/09/12 08:03:20 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Les philosophes sont soit en train de manger, de penser ou de dormir.
	Lorsqu’ils mangent, ils ne peuvent pas penser ou dormir.
	Lorsqu’ils dorment, ils ne peuvent pas manger ou penser.
	Enfin, lorsqu’ils pensent, ils ne peuvent pas manger ou dormir.

• Il y a également des fourchettes sur la table. Il y a autant de fourchettes que
de philosophes.

• Puisque servir et manger des spaghetti à l’aide d’une seule fourchette n’est pas
chose facile, un philosophe prend la fourchette sur sa gauche et celle sur sa droite,
soit une fourchette dans chaque main, afin de manger.

• Quand un philosophe a fini de manger, il repose les fourchettes sur la table et se
met à dormir. Une fois réveillé, il se remet à penser. La simulation prend fin si un
philosophe meurt de faim.

• Chaque philosophe a besoin de manger et ne doit pas mourir de faim.
• Les philosophes ne communiquent pas entre eux.
• Les philosophes ne peuvent pas savoir si l’un d’entre eux est sur le point de mourir.
• Inutile de préciser que les philosophes ne doivent pas mourir !

• Chaque programme doit prendre les arguments suivants :
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/

#include "philo.h"
#include <stdlib.h>

int main (int argc, char **argv)
{
	t_philo philo;
	if (check_errors(argc, argv))
		exit (1);
	arg_init(argv, philo);
	printf("all good\n");
	// pthread_create(philo1, NULL);
}