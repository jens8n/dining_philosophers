/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:52:03 by jebucoy           #+#    #+#             */
/*   Updated: 2023/04/13 16:10:33 by jebucoy          ###   ########.fr       */
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

typedef struct s_sim
{
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	time_to_die;
	size_t	philo_count;
}	t_sim;

typedef struct s_philo
{

}	t_philo;

bool	validate_arg(char **av);
size_t	atos(char *str);
#endif