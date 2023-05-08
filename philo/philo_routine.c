/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:13:32 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/08 22:02:24 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//converts current time in milisecond
size_t	get_usec()
{
	struct timeval	cur;
	size_t			milli;

	gettimeofday(&cur, NULL);
	milli = (cur.tv_sec * 1000) + (cur.tv_usec / 1000);
	return (milli);
}

void	philo_eat(t_philo *philo)
{
	size_t	left;
	size_t	right;

	left = philo->philo_idx;
	right = left + 1;
	if (left == philo->sim->philo_count - 1)
			right = 0;
	while (1)
	{
		if (check_death(philo) == false)
		{
			pthread_mutex_lock(&philo->sim->msg_mtx);
			printf("philosopher %zu has died\n", left);
			pthread_mutex_unlock(&philo->sim->msg_mtx);
			exit(1); //not allowed to use
		}
		pthread_mutex_lock(&philo->sim->fork_mtx[left]);
		pthread_mutex_lock(&philo->sim->fork_mtx[right]);
		if (philo->sim->forks[left] == false && philo->sim->forks[right] == false)
		{
			philo->sim->forks[left] = true;
			philo->sim->forks[right] = true;
			philo->lasteat_time = get_usec();
			pthread_mutex_lock(&philo->sim->msg_mtx);
			printf(RED"%zum ", philo->lasteat_time - philo->sim->start_time);
			printf("philosopher %zu is eating\n"RESET, philo->philo_idx);
			pthread_mutex_unlock(&philo->sim->msg_mtx);
			usleep(philo->sim->tte * 1000);
			philo->sim->forks[left] = false;
			philo->sim->forks[right] = false;
			break ;
		}
		pthread_mutex_unlock(&philo->sim->fork_mtx[left]);
		pthread_mutex_unlock(&philo->sim->fork_mtx[right]);
	}
	pthread_mutex_unlock(&philo->sim->fork_mtx[left]);
	pthread_mutex_unlock(&philo->sim->fork_mtx[right]);
}

//returns false if philo is dead
bool	check_death(t_philo *philo)
{
	if (get_usec() - philo->lasteat_time > philo->sim->ttd)
		return (false);
	return (true);
}

void	philo_think(t_philo *philo)
{
	size_t	think_tv;

	think_tv = get_usec();
	pthread_mutex_lock(&philo->sim->msg_mtx);
	printf(BLUE"%zum ", think_tv - philo->sim->start_time);
	printf("philosopher %zu is thicking\n"RESET, philo->philo_idx);
	pthread_mutex_unlock(&philo->sim->msg_mtx);
	
}

void	philo_sleep(t_philo *philo)
{
	size_t	sleep_tv;

	sleep_tv = get_usec();
	pthread_mutex_lock(&philo->sim->msg_mtx);
	printf("%zum ", sleep_tv - philo->sim->start_time);
	printf("philosopher %zu is sleeping\n", philo->philo_idx);
	pthread_mutex_unlock(&philo->sim->msg_mtx);
	usleep(philo->sim->tts);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		philo_eat(p);
		philo_think(p);
		philo_sleep(p);
	}
}
