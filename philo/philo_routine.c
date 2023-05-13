/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:13:32 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/14 03:37:03 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//converts current time in milisecond
size_t	get_milli()
{
	struct timeval	cur;
	size_t			milli;

	gettimeofday(&cur, NULL);
	milli = (cur.tv_sec * 1000) + (cur.tv_usec / 1000);
	return (milli);
}

bool	my_sleep(t_philo *p, size_t sleep_time)
{
	size_t	start_time;
	size_t	cur;
	
	start_time = get_milli();
	cur = 0;
	while (cur != start_time + sleep_time)
	{
		if (check_death(p) == true)
			return (false);
		cur = get_milli();
		usleep(100);
	}
	return (true);
}

void	check_fork_status(t_philo *p, size_t idx, size_t *flag)
{
	pthread_mutex_lock(&p->sim->fork_mtx[idx]);
	if (p->sim->fork[idx] == false)
	{
		p->sim->fork[idx] = true;
		(*flag)++;
	}
	pthread_mutex_unlock(&p->sim->fork_mtx[idx]);
}

void	release_fork(t_philo *p, size_t left, size_t right)
{
	pthread_mutex_lock(&p->sim->fork_mtx[left]);
	p->sim->fork[left] = false;
	pthread_mutex_unlock(&p->sim->fork_mtx[left]);
	pthread_mutex_lock(&p->sim->fork_mtx[right]);
	p->sim->fork[right] = false;
	pthread_mutex_unlock(&p->sim->fork_mtx[right]);
}

bool	philo_eat(t_philo *p)
{
	size_t	l;
	size_t	r;
	size_t	flag;
	bool	ret;
	
	l = p->p_idx;
	r = l + 1;
	flag = 0;
	ret = true;
	if (l == p->sim->p_count - 1)
			r = 0;
	while (flag < 2 && ret)
	{
		if (check_death(p) == true)
			return (false);
		check_fork_status(p, l, &flag);
		check_fork_status(p, r, &flag);
		if (flag == 2)
		{
			task_log(p, GREEN"eating");
			p->lasteat_time = get_milli();
			ret = my_sleep(p, p->sim->tte);
			release_fork(p, l, r);
		}
	}
	return (ret);
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
