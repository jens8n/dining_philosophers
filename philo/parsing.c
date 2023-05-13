/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:17:50 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/10 20:14:32 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//handle inputs greater than int max

bool	parser(char **av)
{
	if (!validate_arg(av))
	{
		printf("Invalid Arguments\n");
		return (false);
	}
	return (true);
}

bool	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (true);
	else
		return (false);
}

bool	validate_arg(char **av)
{
	int	s;
	int	c;

	s = 1;
	while (av[s])
	{
		c = 0;
		if (av[s][c] == '\0')
			return (false);
		while (av[s][c])
		{
			if (!ft_isdigit(av[s][c]) || av[s][c] == '-')
				return (false);
			c++;
		}
		s++;
	}
	return (true);
}

size_t	atos(char *str)
{
	size_t	i;
	size_t	s;
	size_t	n;

	i = 0;
	s = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	while (str[i] == '+')
		i++;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		if (i > 12)
			return ((size_t)INT_MAX + 1);
		n = n * 10 + (str[i++] - 48);
	}
	return (n * s);
}
