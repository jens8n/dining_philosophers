/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:45:32 by jebucoy           #+#    #+#             */
/*   Updated: 2023/08/17 21:26:57 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_sim_args(char **av, t_sim *sim)
{
	sim->philo_n = atos(av[1]);
	sim->ttd = atos(av[2]);
	sim->tte = atos(av[3]);
	sim->tts = atos(av[4]);
	sim->eat_n = -1;
	if (av[5] != NULL)
		sim->eat_n = atos(av[5]);
	if (sim->philo_n == 0 || sim->ttd == 0 || sim->tte == 0 || sim->tts == 0)
		return (false);
	sim->philo = (t_philo *)ft_calloc(sizeof(t_philo), sim->philo_n); 
	sim->dead_body = false;
	sim->flag = 0;
	pthread_mutex_init(&sim->msg_mtx, NULL);
	pthread_mutex_init(&sim->flag_mtx, NULL);
	define_struct(sim);
	return (true);
}

void	define_struct(t_sim *sim)
{
	size_t	i;

	i = 0;
	sim->fork_mtx = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t),
			sim->philo_n);
	sim->fork = (ssize_t *)ft_calloc(sizeof(ssize_t), sim->philo_n);
	while (i < sim->philo_n)
	{
		sim->philo[i].p_id = i;
		sim->philo[i].sim = sim;
		sim->fork[i] = -1;
		sim->philo[i].meal_count = 0;
		pthread_mutex_init(&sim->fork_mtx[i], NULL);
		i++;
	}
}

void	make_threads(t_sim *sim)
{
	size_t		i;

	i = -1;
	sim->p_th = (pthread_t *)ft_calloc(sizeof(pthread_t), sim->philo_n);
	sim->start_time = get_milli();
	while (++i < sim->philo_n)
	{
		sim->philo[i].lasteat_time = sim->start_time;
		pthread_create(&sim->p_th[i], NULL, routine, (void *)&sim->philo[i]);
		usleep(20);
	}
	i = -1;
	while (++i < sim->philo_n)
	{
		pthread_join(sim->p_th[i], NULL);
	}
	burial(sim);
}
