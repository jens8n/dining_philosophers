/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:45:32 by jebucoy           #+#    #+#             */
/*   Updated: 2023/04/17 21:54:17 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_sim_args(char **av, t_sim *sim, pthread_t *p_th)
{
	t_philo			*philo;
	pthread_mutex_t	mtx;

	sim->philo_count = atos(av[1]);
	sim->time_to_die = atos(av[2]);
	sim->time_to_eat = atos(av[3]);
	sim->time_to_sleep = atos(av[4]);
	if (sim->philo_count == 0 || sim->time_to_die == 0
		|| sim->time_to_eat == 0 || sim->time_to_sleep == 0)
		return ;
	philo = (t_philo *)malloc(sizeof(t_philo) * sim->philo_count);
	define_struct(philo, sim);
	make_threads(philo, p_th);
	pthread_mutex_init(&mtx, NULL);
}

void	define_struct(t_philo *philo, t_sim *sim)
{
	size_t	i;

	i = 0;
	while (i < sim->philo_count)
	{
		philo[i].philo_num = i;
		philo[i].lasteat_time = 0;
		philo[i].sim = sim;
		i++;
	}
}

void	*debug_struct(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	printf("philo_num = %zu\n", p->philo_num);
	printf("last eat time = %zu\n", p->lasteat_time);
	return (NULL);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	
}

void	make_threads(t_philo *philo, pthread_t *p_th)
{
	size_t			i;
	int				time;
	struct timeval	cur_tv;

	i = -1;
	time = gettimeofday(&cur_tv, NULL);
	p_th = (pthread_t *)malloc(sizeof(pthread_t) * philo->sim->philo_count);
	while (++i < philo->sim->philo_count)
		pthread_create(&p_th[i], NULL, debug_struct, (void *)&philo[i]);
	i = -1;
	while (++i < philo->sim->philo_count)
		pthread_join(p_th[i], NULL);
}