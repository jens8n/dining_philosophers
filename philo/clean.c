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

// - function to clean up before stopping program
// *free all allocations
// *destroy all make_threads
// return (true or false);

bool   burial(t_philo *p)
{
    size_t i;

    i = -1;
    death_log(p, get_milli() - p->sim->start_time);
    while (++i < p->sim->p_count)
        pthread_mutex_destroy(&p->sim->fork_mtx[i]);
    free(p->sim->philo);
    free(p->sim->fork);
    free(p->sim->fork_mtx);
    return (true);
}
