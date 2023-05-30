/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:45:32 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/30 23:33:53 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// handle stopping simulation in a clean way

bool	init_sim_args(char **av, t_sim *sim)
{
	sim->p_count = atos(av[1]);
	sim->ttd = atos(av[2]);
	sim->tte = atos(av[3]);
	sim->tts = atos(av[4]);
	if (av[5] != NULL)
		sim->eat_rep = atos(av[5]);
	sim->philo = (t_philo *)ft_calloc(sizeof(t_philo), sim->p_count); 
	sim->dead_body = false;
	pthread_mutex_init(&sim->msg_mtx, NULL);
	define_struct(sim);
	return (true);
}

void	define_struct(t_sim *sim)
{
	size_t	i;

	i = 0;
	sim->fork_mtx = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), sim->p_count);
	sim->fork = (ssize_t *)ft_calloc(sizeof(ssize_t), sim->p_count);
	while (i < sim->p_count)
	{
		sim->philo[i].p_id = i;
		sim->philo[i].sim = sim;
		sim->fork[i] = -1;
		pthread_mutex_init(&sim->fork_mtx[i], NULL);
		i++;
	}
}

void	make_threads(t_philo *p)
{
	size_t		i;

	i = -1;
	p->sim->p_th = (pthread_t *)ft_calloc(sizeof(pthread_t), p->sim->p_count);
	p->sim->start_time = get_milli();
	while (++i < p->sim->p_count)
	{
		p[i].lasteat_time = p->sim->start_time;
		pthread_create(&p->sim->p_th[i], NULL, routine, (void *)&p[i]);
	}
	i = -1;
	while (++i < p->sim->p_count)
	{
		pthread_join(p->sim->p_th[i], NULL);
	}
}