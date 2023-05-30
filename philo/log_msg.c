/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:00:14 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/09 18:00:14 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    fork_log(t_philo *p)
{
    size_t timestamp;

    timestamp = get_milli() - p->sim->start_time;
    pthread_mutex_lock(&p->sim->msg_mtx);
    if (p->sim->dead_body == false)
        printf(YELLOW"%zums Philosopher[%zu] has a taken a fork\n"RESET,
            timestamp, p->p_id + 1);
    pthread_mutex_unlock(&p->sim->msg_mtx);

}

void    task_log(t_philo *p, char *msg, char *rgb)
{
    size_t timestamp;

    timestamp = get_milli() - p->sim->start_time;
    pthread_mutex_lock(&p->sim->msg_mtx);
    if (p->sim->dead_body == false)
        printf("%s%zums Philosopher[%zu] is %s\n"RESET, rgb, timestamp, p->p_id + 1, msg);
    pthread_mutex_unlock(&p->sim->msg_mtx);
}

void    death_log(t_philo *p, size_t timestamp)
{
    pthread_mutex_lock(&p->sim->msg_mtx);
    printf(RED"%zums Philosopher[%zu] is dead\n"RESET, timestamp, p->p_id + 1);
    pthread_mutex_unlock(&p->sim->msg_mtx);
}

// void    eat_log(t_philo *p, size_t timestamp)
// {
//     pthread_mutex_lock(&p->sim->msg_mtx);
//     if (p->sim->dead_body == false)
//         printf(GREEN"%zum Philosopher[%zu] is eating\n"RESET, timestamp, p->p_idx);
//     pthread_mutex_unlock(&p->sim->msg_mtx);
// }

// void    think_log(t_philo *p, size_t timestamp)
// {
//     pthread_mutex_lock(&p->sim->msg_mtx);
// 	if (p->sim->dead_body == false)
//     {
//         printf("%zum ", timestamp);
// 	    printf("Philosopher[%zu] is thinking\n", p->p_idx);
//     }
// 	pthread_mutex_unlock(&p->sim->msg_mtx);
// }

// void    sleep_log(t_philo *p, size_t timestamp)
// {
//     pthread_mutex_lock(&p->sim->msg_mtx);
// 	if (p->sim->dead_body == false)
//     {
//         printf("%zum ", timestamp);
// 	    printf("Philosopher[%zu] is sleeping\n", p->p_idx);
//     }
// 	pthread_mutex_unlock(&p->sim->msg_mtx);
// }