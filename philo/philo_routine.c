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

void	philo_eat(t_philo *philo)
{
	printf("philosopher %zu is eating\n", philo->philo_idx);
}

void	philo_think(t_philo *philo)
{
	printf("philosopher %zu is think\n", philo->philo_idx);
}

void	philo_sleep(t_philo *philo)
{
	printf("philosopher %zu is sleeping\n", philo->philo_idx);
}

void	*routine(void *philo)
{
	t_philo	*p;
	size_t	i;

	i = 0;
	p = (t_philo *)philo;
	while (1)
	{
		philo_eat(p);
		sleep(1);
		philo_think(p);
		sleep(1);
		philo_sleep(p);
		sleep(1);
	}
}
