/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:00:24 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/09 18:00:24 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*m;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	m = (void *)malloc(count * size);
	if (!m)
		return (NULL);
	ft_bzero(m, count * size);
	return (m);
}

//converts current time in milisecond
size_t	get_milli()
{
	struct timeval	cur;
	size_t			milli;

	gettimeofday(&cur, NULL);
	milli = (cur.tv_sec * 1000) + (cur.tv_usec / 1000);
	return (milli);
}

bool	my_sleep(t_philo *p, size_t sleep_time)
{
	size_t	start_time;
	size_t	cur;
	
	start_time = get_milli();
	cur = 0;
	while (cur != start_time + sleep_time)
	{
		if (check_death(p) == true)
			return (false);
		cur = get_milli();
		usleep(100);
	}
	return (true);
}