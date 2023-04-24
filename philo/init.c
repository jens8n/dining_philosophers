/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:45:32 by jebucoy           #+#    #+#             */
/*   Updated: 2023/04/24 20:13:57 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_sim_args(char **av, t_sim *sim)
{
	sim->philo_count = atos(av[1]);
	sim->time_to_die = atos(av[2]);
	sim->time_to_eat = atos(av[3]);
	sim->time_to_sleep = atos(av[4]);
	if (sim->philo_count == 0 || sim->time_to_die == 0
		|| sim->time_to_eat == 0 || sim->time_to_sleep == 0)
		return ;
	sim->philo = (t_philo *)malloc(sizeof(t_philo) * sim->philo_count);
	define_struct(sim);
}

void	define_struct(t_sim *sim)
{
	size_t	i;

	i = 0;
	while (i < sim->philo_count)
	{
		sim->philo[i].philo_idx = i;
		sim->philo[i].lasteat_time = 0;
		sim->philo[i].sim = sim;
		i++;
	}
}


void	*debug_struct(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	printf("philo_count = %zu\n", p->sim->philo_count);
	printf("philo_num = %zu\n", p->philo_idx);
	printf("time_to_die = %zu\n", p->sim->time_to_die);
	printf("time_to_eat = %zu\n", p->sim->time_to_eat);
	printf("time_to_sleep = %zu\n", p->sim->time_to_sleep);
	printf("last eat time = %zu\n", p->lasteat_time);
	return (NULL);
}


void	make_threads(t_philo *philo)
{
	size_t			i;
	pthread_t		*p_th;

	i = -1;
	p_th = (pthread_t *)malloc(sizeof(pthread_t) * philo->sim->philo_count);
	while (++i < philo->sim->philo_count)
		pthread_create(&p_th[i], NULL, routine, (void *)&philo[i]);
	i = -1;
	printf("threads are created\n");
	while (++i < philo->sim->philo_count)
	{
		pthread_join(p_th[i], NULL);
		printf("a threads is joined\n");
	}
}