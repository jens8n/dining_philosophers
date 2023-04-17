/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:52:03 by jebucoy           #+#    #+#             */
/*   Updated: 2023/04/17 18:22:39 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	bool	forks;
	t_philo	*philo;
}	t_sim;

typedef struct s_philo
{
	size_t	philo_num;
	size_t	lasteat_time;
	t_sim	*sim;
}	t_philo;

bool	validate_arg(char **av);
size_t	atos(char *str);
bool	parser(char **av);
void	make_threads(t_philo *philo, pthread_t *p_th);
void	define_struct(t_philo *philo, t_sim *sim);
#endif