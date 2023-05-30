/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:13:32 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/30 23:55:34 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	release_fork(t_philo *p, size_t fork1, size_t fork2)
{
	pthread_mutex_lock(&p->sim->fork_mtx[fork1]);
	p->sim->fork[fork1] = p->p_id;
	pthread_mutex_unlock(&p->sim->fork_mtx[fork1]);
	pthread_mutex_lock(&p->sim->fork_mtx[fork2]);
	p->sim->fork[fork2] = p->p_id;
	pthread_mutex_unlock(&p->sim->fork_mtx[fork2]);
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
		if (forks_held == 1 && p->sim->fork[fork2] != -2 && p->sim->fork[fork2] != p->p_id)
		{
			p->sim->fork[fork2] = -2;
			forks_held++;
		}
		pthread_mutex_unlock(&p->sim->fork_mtx[fork2]);
		usleep(200);
	}
	if (!check_death(p))
	{
		fork_log(p, fork1, fork2);
		task_log(p, GREEN"eating");
		p->lasteat_time = get_milli();
		my_sleep(p, p->sim->tte);
		release_fork(p, fork1, fork2);
	}	
}


bool	philo_eat(t_philo *p)
{
	size_t	l;
	size_t	r;
	
	l = p->p_id;
	r = l + 1;
	if (l == p->sim->p_count - 1)
			r = 0;
	if (p->p_id % 2 == 0)
		pick_forks(p, r, l);
	else
		pick_forks(p, l, r);
	return (true);
}

//returns true if philo is dead
bool	check_death(t_philo *p)
{
	pthread_mutex_lock(&p->sim->msg_mtx);
	if (p->sim->dead_body == true)
	{
		pthread_mutex_unlock(&p->sim->msg_mtx);
		return (true);
	}
	if (get_milli() - p->lasteat_time > p->sim->ttd)
	{
		p->sim->dead_body = true;
		pthread_mutex_unlock(&p->sim->msg_mtx);
		death_log(p, get_milli() - p->sim->start_time);
		return (true);
	}
	pthread_mutex_unlock(&p->sim->msg_mtx);
	return (false);
}

bool	philo_think(t_philo *p)
{
	if(check_death(p) == true)
		return (false);
	task_log(p, "thinking");
	return (true);
}

bool	philo_sleep(t_philo *p)
{
	task_log(p, BLUE"sleeping");
	if (my_sleep(p, p->sim->tts) == false)
		return (false);
	return (true);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		if (!philo_eat(p)
			|| !philo_sleep(p)
			|| !philo_think(p))
			return (NULL);		
	}
}

