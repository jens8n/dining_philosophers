/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:52:03 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/08 21:55:14 by jebucoy          ###   ########.fr       */
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

typedef struct s_philo	t_philo;

typedef struct s_sim
{
	size_t			tte;
	size_t			tts;
	size_t			ttd;
	size_t			philo_count;
	size_t			start_time;
	bool			*forks;
	t_philo			*philo;
	pthread_mutex_t	*fork_mtx;
	pthread_mutex_t	msg_mtx;
}	t_sim;

typedef struct s_philo
{
	size_t			philo_idx;
	size_t			lasteat_time;
	t_sim			*sim;
}	t_philo;

bool	validate_arg(char **av);
bool	parser(char **av);
size_t	atos(char *str);

void	*ft_calloc(size_t count, size_t size);

void	make_threads(t_philo *philo);
void	define_struct(t_sim *sim);
void	init_sim_args(char **av, t_sim *sim);
void	*routine(void *philo);
size_t	get_usec();
bool	check_death(t_philo *philo);

#endif