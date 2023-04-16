/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:20:22 by jebucoy           #+#    #+#             */
/*   Updated: 2023/04/16 19:39:42 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_sim_args(char **av, t_sim *sim, pthread_t *p_th)
{
	t_philo	*philo;

	sim->philo_count = atos(av[1]);
	sim->time_to_die = atos(av[2]);
	sim->time_to_eat = atos(av[3]);
	sim->time_to_sleep = atos(av[4]);
	if (sim->philo_count == 0 || sim->time_to_die == 0
		|| sim->time_to_eat == 0 || sim->time_to_sleep == 0)
		return ;
	philo = (t_philo *)malloc(sizeof(t_philo) * sim->philo_count);
	define_struct(philo, sim);
	makethreads(philo, p_th);
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

void	*printstruct(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	printf("philo_num = %zu\n", p->philo_num);
	printf("last eat time = %zu\n", p->lasteat_time);
	return (NULL);
}

void	makethreads(t_philo *philo, pthread_t *p_th)
{
	size_t	i;

	i = -1;
	p_th = (pthread_t *)malloc(sizeof(pthread_t) * philo->sim->philo_count);
	while (++i < philo->sim->philo_count)
		pthread_create(&p_th[i], NULL, printstruct, (void *)&philo[i]);
	i = -1;
	while (++i < philo->sim->philo_count)
		pthread_join(p_th[i], NULL);
}

int main(int ac, char **av)
{
	t_sim	sim;
	pthread_t	*p_th;

	p_th = NULL;
	if (ac == 6)
	{
		if (parser(av) == true)
		{
			init_sim_args(av, &sim, p_th);
		}
	}
	return(0);
}