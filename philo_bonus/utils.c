/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:00:24 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/09 18:00:24 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	my_sleep(size_t sleep_time)
{
	size_t	start_time;
	size_t	cur;

	start_time = get_milli();
	cur = start_time;
	while (cur - start_time < sleep_time)
	{
		cur = get_milli();
		usleep(1000);
	}
	return (true);
}

void	clean_up(t_sim *sim)
{
	size_t	i;
	char	*sem_name;
	char	*num;

	i = -1;
	sem_unlink("/philo_forks");
	sem_unlink("philo_track_meal");
	sem_unlink("/philo_log");
	sem_unlink("/philo_death");
	sem_close(sim->forks);
	sem_close(sim->track_meal);
	sem_close(sim->msg);
	sem_close(sim->death);
	while (++i < sim->philo_n)
	{
		num = ft_itoa(i);
		sem_name = ft_strjoin("/philo_meal_", num);
		sem_unlink(sem_name);
		sem_close(sim->last_eat_lock[i]);
		free(num);
		free(sem_name);
	}
	free(sim->last_eat_lock);
	free(sim->pid);
}

void	ft_bzero(void *s, size_t n)
{
	memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*m;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	m = (void *)malloc(count * size);
	if (!m)
		return (NULL);
	ft_bzero(m, count * size);
	return (m);
}

//converts current time in milisecond
size_t	get_milli(void)
{
	struct timeval	cur;
	size_t			milli;

	gettimeofday(&cur, NULL);
	milli = (cur.tv_sec * 1000) + (cur.tv_usec / 1000);
	return (milli);
}
