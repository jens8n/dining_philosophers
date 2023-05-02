/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:13:32 by jebucoy           #+#    #+#             */
/*   Updated: 2023/04/24 20:23:53 by jebucoy          ###   ########.fr       */
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
	size_t	eat_tv;

	eat_tv = get_usec();
	printf(RED"%zum ", eat_tv - philo->sim->start_tv);
	printf("philosopher %zu is eating\n"RESET, philo->philo_idx);
}

void	philo_think(t_philo *philo)
{
	size_t	think_tv;

	think_tv = get_usec();
	printf(BLUE"%zum ", think_tv - philo->sim->start_tv);
	printf("philosopher %zu is thicking\n"RESET, philo->philo_idx);
}

void	philo_sleep(t_philo *philo)
{
	size_t	sleep_tv;

	sleep_tv = get_usec();
	printf("%zum ", sleep_tv - philo->sim->start_tv);
	printf("philosopher %zu is sleeping\n", philo->philo_idx);
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
		sleep(1);
	}
}
