/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:33:15 by jebucoy           #+#    #+#             */
/*   Updated: 2023/08/17 21:55:12 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_lock_sem(t_sim *sim)
{
	size_t	i;
	char	*sem_name;
	char	*num;

	i = -1;
	sim->last_eat_lock = (sem_t **)malloc(sizeof(sem_t *) * sim->philo_n);
	while (++i < sim->philo_n)
	{
		num = ft_itoa(i);
		sem_name = ft_strjoin("/philo_meal_", num);
		sem_unlink(sem_name);
		sim->last_eat_lock[i] = sem_open(sem_name, O_CREAT, 0644, 1);
		free(num);
		free(sem_name);
	}
}

bool	init_sim_args(t_sim *sim, char **av)
{
	sim->eat_n = 0;
	sim->philo_n = atos(av[1]);
	sim->ttd = atos(av[2]);
	sim->tte = atos(av[3]);
	sim->tts = atos(av[4]);
	if (av[5] != NULL)
		sim->eat_n = atos(av[5]);
	if (sim->philo_n == 0 || sim->ttd == 0 || sim->tte == 0 || sim->tts == 0)
		return (false);
	sim->p_idx = 1;
	sem_unlink("/philo_forks");
	sim->forks = sem_open("/philo_forks", O_CREAT, 0644, sim->philo_n);
	sem_unlink("philo_track_meal");
	sim->track_meal = sem_open("philo_track_meal", O_CREAT, 0644, sim->philo_n);
	sem_unlink("/philo_log");
	sim->msg = sem_open("/philo_log", O_CREAT, 0644, 1);
	sim->pid = (pid_t *)ft_calloc(sizeof(pid_t), sim->philo_n);
	sem_unlink("/philo_death");
	sim->death = sem_open("/philo_death", O_CREAT, 0644, 1);
	init_lock_sem(sim);
	create_processes(sim);
	return (true);
}

void	run_sim(t_sim *sim, size_t *i)
{
	if (sim->pid[*i] == 0)
	{
		pthread_create(&sim->reaper, NULL, monitor_death, (void *)sim); 
		simulation(sim);
	}
	else
	{
		(*i)++;
		sim->p_idx++;
	}
}

bool	create_processes(t_sim *sim)
{
	size_t	i;

	sim->start_time = get_milli();
	i = 0;
	track_meal(sim, false);
	if (sim->philo_n == 1)
	{
		printf("%zdms Philosopher [%zd] starved to death\n",
			sim->ttd, sim->p_idx);
		return (true);
	}
	while (i < sim->philo_n)
	{
		sim->pid[i] = fork();
		sim->last_eat_time = 0;
		run_sim(sim, &i);
	}
	sem_wait(sim->death);
	track_meal(sim, true);
	sem_wait(sim->death);
	terminate(sim);
	return (true);
}
