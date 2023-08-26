/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:45:40 by jebucoy           #+#    #+#             */
/*   Updated: 2023/08/17 21:54:33 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat_task(t_sim *sim)
{
	sem_wait(sim->forks);
	sem_wait(sim->forks);
	printf(YELLOW"%zdms Philosopher [%zd] has taken a fork\n"RESET,
		get_milli() - sim->start_time, sim->p_idx);
	printf(GREEN"%zdms Philosopher [%zd] is eating\n"RESET,
		get_milli() - sim->start_time, sim->p_idx);
	sem_wait(sim->last_eat_lock[sim->p_idx - 1]);
	sim->last_eat_time = get_milli();
	sem_post(sim->last_eat_lock[sim->p_idx - 1]);
	my_sleep(sim->tte);
	sem_post(sim->forks);
	sem_post(sim->forks);
}

bool	simulation(t_sim *sim)
{
	size_t	track;

	track = 0;
	if ((sim->p_idx - 1) % 2 == 0)
		my_sleep(sim->tte);
	while (1)
	{
		eat_task(sim);
		track++;
		if (track == sim->eat_n)
			sem_post(sim->track_meal);
		printf(BLUE"%zdms Philosopher [%zd] is sleeping\n"RESET,
			get_milli() - sim->start_time, sim->p_idx);
		my_sleep(sim->tts);
		printf(MAGENTA"%zdms Philosopher [%zd] is thinking\n"RESET,
			get_milli() - sim->start_time, sim->p_idx);
	}
}

void	*monitor_death(void *arg)
{
	t_sim	*sim;
	size_t	i;

	i = -1;
	sim = (t_sim *)arg;
	while (1)
	{
		sem_wait(sim->last_eat_lock[sim->p_idx - 1]);
		if (sim->last_eat_time == 0)
			;
		else if (get_milli() - sim->last_eat_time > sim->ttd)
		{
			if (sim->eat_n != 0)
			{
				while (++i < sim->philo_n)
					sem_post(sim->track_meal);
			}
			sem_wait(sim->msg);
			printf("%zdms Philospher [%zd] starved to death\n",
				get_milli() - sim->start_time, sim->p_idx);
			sem_post(sim->death);
		}
		sem_post(sim->last_eat_lock[sim->p_idx - 1]);
		usleep(1000);
	}
}

bool	terminate(t_sim *sim)
{
	size_t	i;

	i = -1;
	while (++i < sim->philo_n)
	{
		kill(sim->pid[i], SIGKILL);
	}
	return (true);
}

void	track_meal(t_sim *sim, bool flag)
{
	size_t	i;

	i = -1;
	if (sim->eat_n > 0)
	{
		while (++i < sim->philo_n)
			sem_wait(sim->track_meal);
		if (flag == true)
			sem_post(sim->death);
	}
}
