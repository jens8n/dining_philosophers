/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:09:42 by jebucoy           #+#    #+#             */
/*   Updated: 2023/08/17 21:25:00 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	complete_meal(t_philo *p)
{
	pthread_mutex_lock(&p->sim->msg_mtx);
	if (p->sim->flag == (ssize_t)p->sim->philo_n)
	{
		pthread_mutex_unlock(&p->sim->msg_mtx);
		return (false);
	}
	pthread_mutex_unlock(&p->sim->msg_mtx);
	return (true);
}

void	release_fork(t_philo *p, size_t fork1, size_t fork2)
{
	pthread_mutex_lock(&p->sim->fork_mtx[fork1]);
	p->sim->fork[fork1] = p->p_id;
	pthread_mutex_unlock(&p->sim->fork_mtx[fork1]);
	pthread_mutex_lock(&p->sim->fork_mtx[fork2]);
	p->sim->fork[fork2] = p->p_id;
	pthread_mutex_unlock(&p->sim->fork_mtx[fork2]);
}

t_mealupdate	track_meals(t_philo *p)
{
	p->meal_count++;
	if (p->meal_count == p->sim->eat_n)
	{
		pthread_mutex_lock(&p->sim->flag_mtx);
		p->sim->flag++;
		if (p->sim->flag == (ssize_t)p->sim->philo_n)
		{
			pthread_mutex_unlock(&p->sim->flag_mtx);
			return (MEAL_COMP);
		}
		pthread_mutex_unlock(&p->sim->flag_mtx);
	}
	return (MEAL_INCOMP);
}

void	pick_forks(t_philo *p, size_t fork1, size_t fork2)
{
	size_t	forks_held;

	forks_held = 0;
	while (forks_held != 2 && !check_death(p))
	{
		pthread_mutex_lock(&p->sim->fork_mtx[fork1]);
		if (p->sim->fork[fork1] != -2 && p->sim->fork[fork1] != p->p_id)
		{
			p->sim->fork[fork1] = -2;
			forks_held++;
		}
		pthread_mutex_unlock(&p->sim->fork_mtx[fork1]);
		pthread_mutex_lock(&p->sim->fork_mtx[fork2]);
		if (forks_held == 1 && p->sim->fork[fork2] != -2
			&& p->sim->fork[fork2] != p->p_id)
		{
			p->sim->fork[fork2] = -2;
			forks_held++;
			fork_log(p);
		}
		pthread_mutex_unlock(&p->sim->fork_mtx[fork2]);
		usleep(200);
	}
}
