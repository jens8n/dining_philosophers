/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:52:03 by jebucoy           #+#    #+#             */
/*   Updated: 2023/08/17 21:30:09 by jebucoy          ###   ########.fr       */
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

typedef enum s_mealupdate {
	MEAL_COMP,
	MEAL_INCOMP,
}	t_mealupdate;

typedef struct s_philo	t_philo;

typedef struct s_sim
{
	size_t			tte;
	size_t			tts;
	size_t			ttd;
	size_t			philo_n;
	size_t			start_time;
	ssize_t			eat_n;
	ssize_t			*fork;
	t_philo			*philo;
	pthread_mutex_t	*fork_mtx;
	pthread_mutex_t	msg_mtx;
	pthread_mutex_t	flag_mtx;
	pthread_t		*p_th;
	bool			dead_body;
	ssize_t			flag;
}	t_sim;

typedef struct s_philo
{
	ssize_t			p_id;
	ssize_t			meal_count;
	size_t			lasteat_time;
	t_sim			*sim;
}	t_philo;

//parsing
bool			validate_arg(char **av);
bool			parser(char **av);
size_t			atos(char *str);

//utils
void			*ft_calloc(size_t count, size_t size);
bool			my_sleep(t_philo *philo, size_t sleep_time);
size_t			get_milli(void);
bool			check_death(t_philo *philo);

//initialization
void			make_threads(t_sim *sim);
void			define_struct(t_sim *sim);
bool			init_sim_args(char **av, t_sim *sim);

//log message
void			death_log(t_philo *philo, size_t timestamp);
void			task_log(t_philo *p, char *msg, char *rgb);
void			fork_log(t_philo *p);

//eat task utils
t_mealupdate	track_meals(t_philo *p);
void			pick_forks(t_philo *p, size_t fork1, size_t fork2);
void			release_fork(t_philo *p, size_t fork1, size_t fork2);
bool			complete_meal(t_philo *p);

//sim
void			*routine(void *philo);
bool			burial(t_sim *sim);

#endif