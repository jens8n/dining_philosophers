/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:20:22 by jebucoy           #+#    #+#             */
/*   Updated: 2023/08/17 21:44:41 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_sim			sim;

	if (ac < 5 || ac > 6)
	{
		printf(RED"Error: ./philo [num of philos] [time to die] [time to eat]");
		printf(" [time to sleep] *[meal count]\n"RESET);
		return (1);
	}
	if (parser(av) == true)
	{
		if (init_sim_args(&sim, av) == false)
		{
			printf("Error: Input must be > 0\n");
			return (1);
		}
		clean_up(&sim);
	}
	return (0);
}
