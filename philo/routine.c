/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:13:32 by jebucoy           #+#    #+#             */
/*   Updated: 2023/08/17 21:27:45 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_eat(t_philo *p)
{
	size_t	l;
	size_t	r;

	l = p->p_id;
	r = l + 1;
	if (l == p->sim->philo_n - 1)
		r = 0;
	if (p->p_id % 2 == 0)
		pick_forks(p, r, l);
	else
		pick_forks(p, l, r);
	if (!check_death(p))
	{
		task_log(p, "eating", GREEN);
		p->lasteat_time = get_milli();
		my_sleep(p, p->sim->tte);
		release_fork(p, l, r);
		if (p->sim->eat_n != -1)
			if (track_meals(p) == MEAL_COMP)
				return (false);
	}
	if (complete_meal(p) == false)
		return (false);
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
	if (check_death(p) == true)
		return (false);
	task_log(p, "thinking", MAGENTA);
	return (true);
}

bool	philo_sleep(t_philo *p)
{
	task_log(p, "sleeping", BLUE);
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
		if (!philo_eat(p))
		{
			return (NULL);
		}
		if (!philo_sleep(p)
			|| !philo_think(p))
			return (NULL);
	}
}
