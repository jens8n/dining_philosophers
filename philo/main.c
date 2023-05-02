/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:20:22 by jebucoy           #+#    #+#             */
/*   Updated: 2023/04/24 17:21:39 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_sim			sim;
	if (ac < 5 || ac > 6)
	{
		printf("error\n");
		return (1);
	}
	if (parser(av) == true)
	{
		init_sim_args(av, &sim);
		make_threads(sim.philo);
	}
	return (0);
}
