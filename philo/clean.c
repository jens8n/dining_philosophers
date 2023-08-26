/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:28:14 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/13 19:28:14 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	burial(t_sim *sim)
{
	size_t	i;

	i = -1;
	free(sim->fork);
	free(sim->philo);
	while (++i < sim->philo_n)
		pthread_mutex_destroy(&sim->fork_mtx[i]);
	free(sim->fork_mtx);
	pthread_mutex_destroy(&sim->msg_mtx);
	pthread_mutex_destroy(&sim->flag_mtx);
	free(sim->p_th);
	return (true);
}
