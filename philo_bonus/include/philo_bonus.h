/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:43:30 by jebucoy           #+#    #+#             */
/*   Updated: 2023/08/17 22:02:00 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define RESET   "\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"      
# define MAGENTA "\033[35m"

# include <sys/types.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>
# include <string.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>

typedef struct s_sim
{
	size_t		tte;
	size_t		ttd;
	size_t		tts;
	size_t		philo_n;
	size_t		start_time;
	size_t		last_eat_time;
	size_t		eat_n;
	size_t		p_idx;
	sem_t		*forks;
	sem_t		*track_meal;
	sem_t		*msg;
	sem_t		**last_eat_lock;
	sem_t		*death;
	pthread_t	reaper;
	pid_t		*pid;
}	t_sim;

//parsing
bool	parser(char **av);
bool	ft_isdigit(int c);
bool	validate_arg(char **av);

//utils
size_t	atos(char *str);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	get_milli(void);
bool	my_sleep(size_t sleep_time);

//initialization
bool	init_sim_args(t_sim *sim, char **av);
bool	simulation(t_sim *sim);
bool	create_processes(t_sim *sim);

//tasks
void	*monitor_death(void *arg);
void	track_meal(t_sim *sim, bool flag);

// end program
bool	terminate(t_sim *sim);
void	clean_up(t_sim *sim);

#endif