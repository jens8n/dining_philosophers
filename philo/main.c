/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:20:22 by jebucoy           #+#    #+#             */
/*   Updated: 2023/07/31 17:06:53 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//fix deadlock
//implement amount of time to eat

void	*debug_struct(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	printf("philo_count = %zu\n", p->sim->p_count);
	printf("philo_num = %zu\n", p->p_id);
	printf("time_to_die = %zu\n", p->sim->ttd);
	printf("time_to_eat = %zu\n", p->sim->tte);
	printf("time_to_sleep = %zu\n", p->sim->tts);
	printf("last eat time = %zu\n", p->lasteat_time);
	return (NULL);
}

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
			printf("Error: Input must be > 0\n");
			return (1);
		}
		make_threads(sim.philo);
	}
	return (0);
}