/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:20:22 by jebucoy           #+#    #+#             */
/*   Updated: 2023/04/13 16:11:57 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_sim_args(char **av, t_sim sim)
{
	philo->philo_count = atos(av[1]);
	philo->time_to_die = atos(av[2]);
	philo->time_to_eat = atos(av[3]);
	philo->time_to_sleep = atos(av[4]);
	if (philo->philo_count == 0 || philo->time_to_die == 0
		|| philo->time_to_eat == 0 || philo->time_to_sleep == 0)
		return (NULL);
}

int main(int ac, char **av)
{
	t_sim	sim;
	t_philo	*philo;

	if (ac == 5)
	{
		if (parser(av) == true)
		{
			init_sim_args(av, &philo);
		}
	}
	return(0);
}