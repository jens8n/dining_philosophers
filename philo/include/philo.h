/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:52:03 by jebucoy           #+#    #+#             */
/*   Updated: 2023/04/24 20:20:47 by jebucoy          ###   ########.fr       */
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

typedef struct s_philo	t_philo;

typedef struct s_sim
{
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	time_to_die;
	size_t	philo_count;
	size_t	start_tv;
	bool	forks;
	t_philo	*philo;
}	t_sim;

typedef struct s_philo
{
	size_t	philo_idx;
	size_t	lasteat_time;
	t_sim	*sim;
}	t_philo;

bool	validate_arg(char **av);
size_t	atos(char *str);
bool	parser(char **av);
void	make_threads(t_philo *philo);
void	define_struct(t_sim *sim);
void	init_sim_args(char **av, t_sim *sim);
void	*routine(void *philo);
size_t	get_usec();

#endif