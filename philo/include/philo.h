/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:52:03 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/31 01:02:48 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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

typedef struct s_philo	t_philo;

typedef struct s_sim
{
	size_t			tte;
	size_t			tts;
	size_t			ttd;
	size_t			p_count;
	size_t			start_time;
	size_t			eat_rep;
	ssize_t			*fork;
	t_philo			*philo;
	pthread_mutex_t	*fork_mtx;
	pthread_mutex_t	msg_mtx;
	pthread_mutex_t	flag_mtx;
	pthread_t		*p_th;
	bool			dead_body;
	size_t			flag;
}	t_sim;

typedef struct s_philo
{
	ssize_t			p_id;
	size_t			meal_count;
	size_t			lasteat_time;
	t_sim			*sim;
}	t_philo;

bool	validate_arg(char **av);
bool	parser(char **av);
size_t	atos(char *str);
void	*ft_calloc(size_t count, size_t size);
bool	my_sleep(t_philo *philo, size_t sleep_time);
size_t	get_milli(void);

void	eat_log(t_philo *philo, size_t timestamp);
void    think_log(t_philo *p, size_t timestamp);
void    sleep_log(t_philo *p, size_t timestamp);
void	death_log(t_philo *philo, size_t timestamp);
void    task_log(t_philo *p, char *msg, char *rgb);
void    fork_log(t_philo *p);

bool	check_death(t_philo *philo);
bool	burial(t_philo *p);

void	make_threads(t_philo *philo);
void	define_struct(t_sim *sim);
bool	init_sim_args(char **av, t_sim *sim);
void	*routine(void *philo);

#endif