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

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
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