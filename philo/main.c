/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:20:22 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/14 02:52:10 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int ac, char **av)
{
	t_sim			sim;
	if (ac < 5 || ac > 6)
	{
		printf(RED"Error: ./philo [num of philos] [time to die] [time to eat]");
		printf(" [time to sleep] *[number of times each philosopher must eat]\n"RESET);
		return (1);
	}
	if (parser(av) == true)
	{
		if (init_sim_args(av, &sim) == false)
		{
			printf("Error: Input must be positive values\n");
			return (1);
		}
		make_threads(sim.philo);
	}
	return (0);
}